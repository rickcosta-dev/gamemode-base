/* 
 RickZIn021 
 github: https://github.com/rickcosta-dev 
 repositorio: https://github.com/rickcosta-dev/gamemode-base 
 com licensa apache 2.0 
 */

// -----------------------------------------------------------------------
//  Inicializa o Banco de Dados
// -----------------------------------------------------------------------

stock InitDatabase()
{
    db_handle = db_open(DB_NAME);
    if(db_handle)
    {
        db_free_result(db_query(db_handle, "CREATE TABLE IF NOT EXISTS players (\
            id INTEGER PRIMARY KEY AUTOINCREMENT,\
            name TEXT,\
            senha TEXT,\
            ip TEXT,\
            dinheiro INTEGER DEFAULT 5000,\
            level INTEGER DEFAULT 1,\
            skin INTEGER DEFAULT 0,\
            genero INTEGER DEFAULT 0,\
            admin INTEGER DEFAULT 0,\
            interior INTEGER DEFAULT 0,\
            virtualw INTEGER DEFAULT 0,\
            vidahp REAL DEFAULT 100.0,\
            coletehp REAL DEFAULT 0.0,\
            posx REAL DEFAULT 836.8967,\
            posy REAL DEFAULT -1341.8452,\
            posz REAL DEFAULT 7.1719,\
            posr REAL DEFAULT 84.5851,\
            dia INTEGER,\
            mes INTEGER,\
            ano INTEGER)"));
        print("[SQLite] Banco de dados carregado com sucesso.");
    }
    else
    {
        print("[SQLite] Erro ao abrir banco de dados.");
    }
}

// -----------------------------------------------------------------------
//  Cria o registro do player no banco de dados
// -----------------------------------------------------------------------

stock CriarDadosPlayer(playerid)
{
    new Day, Mes, Ano, query[512];
    getdate(Ano, Mes, Day);
    GetPlayerIp(playerid, PlayerInfo[playerid][IP], 16);

    PlayerInfo[playerid][PosX] = 836.8967;
    PlayerInfo[playerid][PosY] = -1341.8452;
    PlayerInfo[playerid][PosZ] = 7.1719;
    PlayerInfo[playerid][PosR] = 84.5851;
    PlayerInfo[playerid][Skin] = (VGenero[playerid] == 0) ? 299 : 12; 

    format(query, sizeof(query), 
        "INSERT INTO players (name, senha, ip, dia, mes, ano, posx, posy, posz, posr, skin, genero) VALUES ('%s', '%s', '%s', %d, %d, %d, %.4f, %.4f, %.4f, %.4f, %d, %d)",
        PlayerName(playerid), VSenha[playerid], PlayerInfo[playerid][IP], Day, Mes, Ano, 
        PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ], PlayerInfo[playerid][PosR],
        PlayerInfo[playerid][Skin], VGenero[playerid]);
    
    db_free_result(db_query(db_handle, query));

    new DBResult:res = db_query(db_handle, "SELECT last_insert_rowid()");
    if(res)
    {
        PlayerInfo[playerid][IDF] = db_get_field_assoc_int(res, "last_insert_rowid()");
        db_free_result(res);
    }

    CarregarDadosPlayer(playerid);

    VSenha[playerid][0] = '\0';
    VGenero[playerid]   = -1;
    return 1;
}

// -----------------------------------------------------------------------
//  Salva os dados atuais do player no banco de dados
// -----------------------------------------------------------------------

stock SalvarDados(playerid)
{
    if(!VerificarLogin[playerid]) return 0;

    new Float:X, Float:Y, Float:Z, Float:R, Float:vida, Float:colete, query[1024];
    
    if(IsPlayerInAnyVehicle(playerid))
    {
        GetVehiclePos(GetPlayerVehicleID(playerid), X, Y, Z);
        GetVehicleZAngle(GetPlayerVehicleID(playerid), R);
    }
    else
    {
        GetPlayerPos(playerid, X, Y, Z);
        GetPlayerFacingAngle(playerid, R);
    }

    if(X == 0.0 && Y == 0.0) return 0;

    GetPlayerHealth(playerid, vida);
    GetPlayerArmour(playerid, colete);

    PlayerInfo[playerid][PosX] = X;
    PlayerInfo[playerid][PosY] = Y;
    PlayerInfo[playerid][PosZ] = Z;
    PlayerInfo[playerid][PosR] = R;
    PlayerInfo[playerid][VidaHP] = vida;
    PlayerInfo[playerid][ColeteHP] = colete;

    format(query, sizeof(query),
        "UPDATE players SET dinheiro=%d, level=%d, skin=%d, genero=%d, admin=%d, interior=%d, virtualw=%d, vidahp=%.4f, coletehp=%.4f, posx=%.4f, posy=%.4f, posz=%.4f, posr=%.4f WHERE id=%d",
        GetPlayerMoney(playerid), GetPlayerScore(playerid), GetPlayerSkin(playerid),
        PlayerInfo[playerid][Genero], PlayerInfo[playerid][Admin], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid),
        vida, colete, X, Y, Z, R, PlayerInfo[playerid][IDF]);

    db_free_result(db_query(db_handle, query));
    printf("[SQL] Dados de %s salvos. Pos: %.2f, %.2f, %.2f", PlayerName(playerid), X, Y, Z);
    return 1;
}

// -----------------------------------------------------------------------
//  Monta o titulo do player com base no level
// -----------------------------------------------------------------------

static stock ObterTitulo(level, titulo[], len)
{
    if     (level >= 100) format(titulo, len, "Lendario");
    else if(level >= 75)  format(titulo, len, "Mestre");
    else if(level >= 50)  format(titulo, len, "Veterano");
    else if(level >= 25)  format(titulo, len, "Experiente");
    else if(level >= 10)  format(titulo, len, "Iniciante");
    else                  format(titulo, len, "Novato");
}

// -----------------------------------------------------------------------
//  Monta o cargo do player com base no nivel de admin
// -----------------------------------------------------------------------

static stock ObterCargo(admin, cargo[], len)
{
    switch(admin)
    {
        case ADMIN_FUNDADOR:    format(cargo, len, "{FF8282}Fundador");
        case ADMIN_SUBDONO:     format(cargo, len, "{FF8282}Sub Dono");
        case ADMIN_COORDENADOR: format(cargo, len, "{FF8282}Coordenador");
        case ADMIN_GERENTE:     format(cargo, len, "{FF8282}Gerente");
        case ADMIN_SUPERVISOR:  format(cargo, len, "{FF8282}Supervisor");
        case ADMIN_ADMIN:       format(cargo, len, "{FF8282}Administrador");
        case ADMIN_MOD:         format(cargo, len, "{FF8282}Moderador");
        case ADMIN_AJUDANTE:    format(cargo, len, "{FF8282}Ajudante");
        default:                format(cargo, len, "{AAAAAA}Jogador");
    }
}

// -----------------------------------------------------------------------
//  Carrega os dados do banco de dados
// -----------------------------------------------------------------------

stock CarregarDadosPlayer(playerid)
{
    new query[128], DBResult:res;
    format(query, sizeof(query), "SELECT * FROM players WHERE name = '%s' LIMIT 1", PlayerName(playerid));
    res = db_query(db_handle, query);

    if(res && db_num_rows(res) > 0)
    {
        db_get_field_assoc(res, "ip", PlayerInfo[playerid][IP], 16);
        PlayerInfo[playerid][IDF]       = db_get_field_assoc_int(res, "id");
        PlayerInfo[playerid][Genero]    = db_get_field_assoc_int(res, "genero");
        PlayerInfo[playerid][Admin]     = db_get_field_assoc_int(res, "admin");
        PlayerInfo[playerid][PosX]      = db_get_field_assoc_float(res, "posx");
        PlayerInfo[playerid][PosY]      = db_get_field_assoc_float(res, "posy");
        PlayerInfo[playerid][PosZ]      = db_get_field_assoc_float(res, "posz");
        PlayerInfo[playerid][PosR]      = db_get_field_assoc_float(res, "posr");
        PlayerInfo[playerid][Dinheiro]  = db_get_field_assoc_int(res, "dinheiro");

        printf("[DEBUG] Carregado player %s: Pos %.2f, %.2f, %.2f", PlayerName(playerid), PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ]);

        PlayerInfo[playerid][Level]     = db_get_field_assoc_int(res, "level");
        PlayerInfo[playerid][Skin]      = db_get_field_assoc_int(res, "skin");
        PlayerInfo[playerid][VidaHP]    = db_get_field_assoc_float(res, "vidahp");
        PlayerInfo[playerid][ColeteHP]  = db_get_field_assoc_float(res, "coletehp");

        db_free_result(res);

        VerificarLogin[playerid] = true;
        AguardandoBV[playerid]   = true;

        EsconderLoginTD(playerid);
        EsconderRegistroTD(playerid);

        new level  = PlayerInfo[playerid][Level];
        new admin  = PlayerInfo[playerid][Admin];
        new idf    = PlayerInfo[playerid][IDF];
        new titulo[32], cargo[32];
        ObterTitulo(level, titulo, sizeof(titulo));
        ObterCargo(admin, cargo, sizeof(cargo));

        new bv[512], bv2[128];
        format(bv,  sizeof(bv),  "{FFFFFF}Ola, {9281F4}%s{FFFFFF}!\n\n", PlayerName(playerid));
        format(bv2, sizeof(bv2), "Seu ID Fixo: {9281F4}%d\n", idf);
        strcat(bv, bv2, sizeof(bv));
        format(bv2, sizeof(bv2), "Seu Nivel: {9281F4}%d  {FFFFFF}(%s)\n", level, titulo);
        strcat(bv, bv2, sizeof(bv));
        format(bv2, sizeof(bv2), "Seu Cargo: %s\n\n", cargo);
        strcat(bv, bv2, sizeof(bv));
        strcat(bv, "{AAAAAA}Aperte em 'Jogar' para iniciar sua jornada.", sizeof(bv));

        ShowPlayerDialog(playerid, DIALOG_BOASVINDAS, DIALOG_STYLE_MSGBOX,
            "[{9281F4}RickZin021{FFFFFF}] Informacoes da Conta",
            bv, "Jogar", "");

        IDCarregando(playerid);
    }
    return 1;
}

// -----------------------------------------------------------------------
//  Aplica o spawn do player (posicao salva)
// -----------------------------------------------------------------------

stock SetPlayerSpawn(playerid)
{
    if(!VerificarLogin[playerid]) return 0;

    DeletePVar(playerid, "Spawning");

    if(PlayerInfo[playerid][PosX] == 0.0 && PlayerInfo[playerid][PosY] == 0.0)
    {
        PlayerInfo[playerid][PosX] = 836.8967;
        PlayerInfo[playerid][PosY] = -1341.8452;
        PlayerInfo[playerid][PosZ] = 7.1719;
        PlayerInfo[playerid][PosR] = 84.5851;
    }

    SetPlayerPos(playerid, PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ]);
    SetPlayerFacingAngle(playerid, PlayerInfo[playerid][PosR]);
    SetPlayerInterior(playerid, PlayerInfo[playerid][Interior]);
    SetPlayerVirtualWorld(playerid, PlayerInfo[playerid][VirtualW]);
    SetPlayerSkin(playerid, PlayerInfo[playerid][Skin]);

    SetPlayerHealth(playerid, PlayerInfo[playerid][VidaHP]);
    SetPlayerArmour(playerid, PlayerInfo[playerid][ColeteHP]);
    
    TogglePlayerControllable(playerid, false);
    SetTimerEx("Descongelar", 2000, false, "i", playerid);
    return 1;
}

forward SetPlayerSpawnTimer(playerid);
public SetPlayerSpawnTimer(playerid)
{
    if(PlayerInfo[playerid][Atordoado])
    {
        ApplyAnimation(playerid, "PED", "FLOOR_hit_f", 4.1, 0, 1, 1, 1, 0, 1);
        return 1;
    }
    SetPlayerSpawn(playerid);
    return 1;
}

// -----------------------------------------------------------------------
//  Efetua o spawn do player
// -----------------------------------------------------------------------

stock SpawnPlayerLogado(playerid)
{
    if(!VerificarLogin[playerid]) return 0;

    AguardandoBV[playerid] = false;

    LimparChat(playerid, 25);
    
    EsconderLoginTD(playerid);
    EsconderRegistroTD(playerid);

    SetSpawnInfo(playerid, NO_TEAM, PlayerInfo[playerid][Skin],
        PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY],
        PlayerInfo[playerid][PosZ], PlayerInfo[playerid][PosR],
        0, 0, 0, 0, 0, 0);

    TogglePlayerSpectating(playerid, false);
    return 1;
}
