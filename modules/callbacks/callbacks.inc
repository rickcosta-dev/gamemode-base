/* 
 RickZIn021 
 github: https://github.com/rickcosta-dev 
 repositorio: https://github.com/rickcosta-dev/gamemode-base 
 com licensa apache 2.0 
 */

// -----------------------------------------------------------------------
//  Inicializacao da gamemode
// -----------------------------------------------------------------------

public OnGameModeInit()
{
    InitDatabase();

    ShowNameTags(0);
    UsePlayerPedAnims();
    ShowPlayerMarkers(0);
    AllowInteriorWeapons(1);
    EnableStuntBonusForAll(0);
    DisableInteriorEnterExits();
    SetNameTagDrawDistance(10.0);
    SetGameModeText("Base RickZin021");

    SetTimer("UmSegundo",       1000, true);
    return 1;
}

public OnGameModeExit()
{
    foreach(new i : Player)
    {
        if(VerificarLogin[i])
            SalvarDados(i);
    }
    return 1;
}

// -----------------------------------------------------------------------
//  Conexao e desconexao
// -----------------------------------------------------------------------

stock ShowAuthDialog(playerid)
{
    new query[128], DBResult:res;
    format(query, sizeof(query), "SELECT id FROM players WHERE name = '%s' LIMIT 1", PlayerName(playerid));
    res = db_query(db_handle, query);

    if(res && db_num_rows(res) > 0)
    {
        EstaRegistrado[playerid] = true;
        db_free_result(res);
        MostrarLoginTD(playerid);
    }
    else
    {
        EstaRegistrado[playerid] = false;
        if(res) db_free_result(res);
        MostrarRegistroTD(playerid);
    }

    TogglePlayerSpectating(playerid, true);
    InterpolateCameraPos(playerid,
        1153.784301, -873.832763, 102.585563,
        1393.273925, -885.912109, 98.404487,
        40000, CAMERA_CUT);
    return 1;
}

public OnPlayerConnect(playerid)
{
    ResetarDadosPlayer(playerid);
    LimparChat(playerid, 30);
    SetPlayerColor(playerid, -1);
    
    CriarNotifyTD(playerid);
    CriarAuthTD(playerid);
    CriarLoadTD(playerid);
    CriarDeathTD(playerid);

    MostrarLoadScreen(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    if(VerificarLogin[playerid])
        SalvarDados(playerid);

    ResetarDadosPlayer(playerid);
    return 1;
    #pragma unused reason
}

// -----------------------------------------------------------------------
//  Tela de selecao
// -----------------------------------------------------------------------

public OnPlayerRequestClass(playerid, classid)
{
    return 1;
    #pragma unused classid
}

// -----------------------------------------------------------------------
//  Spawn
// -----------------------------------------------------------------------

public OnPlayerSpawn(playerid)
{
    if(!VerificarLogin[playerid])
    {
        SetTimerEx("KickPlayer", 100, false, "i", playerid);
        return 1;
    }

    if(PlayerInfo[playerid][Atordoado])
    {
        SetCameraBehindPlayer(playerid);

        SetPlayerPos(playerid, PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ]);
        SetPlayerFacingAngle(playerid, PlayerInfo[playerid][PosR]);
        
        TogglePlayerControllable(playerid, false);
        SetTimerEx("SetPlayerSpawnTimer", 200, false, "i", playerid);
        
        MostrarDeathTD(playerid);
        return 1;
    }

    if(AguardandoBV[playerid])
        return 1;

    if(GetPVarInt(playerid, "Spawning")) return 1;
    SetPVarInt(playerid, "Spawning", 1);

    SetPlayerColor(playerid, -1);
    GivePlayerMoney(playerid, PlayerInfo[playerid][Dinheiro]);
    SetPlayerScore(playerid, PlayerInfo[playerid][Level]);
    SetPlayerHealth(playerid, PlayerInfo[playerid][VidaHP]);
    SetPlayerArmour(playerid, PlayerInfo[playerid][ColeteHP]);

    SetTimerEx("SetPlayerSpawnTimer", 800, false, "i", playerid);

    PlayerInfo[playerid][Dinheiro] = 0;

    SetTimerEx("IDCarregando", 500, false, "i", playerid);
    NT(playerid, "Bem-vindo! Use /ajuda para ver os comandos.", 8, "Success");
    return 1;
}

// -----------------------------------------------------------------------
//  Morte e chat
// -----------------------------------------------------------------------

public OnPlayerDeath(playerid, killerid, reason)
{
    GetPlayerPos(playerid, PlayerInfo[playerid][PosX], PlayerInfo[playerid][PosY], PlayerInfo[playerid][PosZ]);
    GetPlayerFacingAngle(playerid, PlayerInfo[playerid][PosR]);
    
    PlayerInfo[playerid][PosZ] -= 0.50;

    PlayerInfo[playerid][Atordoado] = 1;
    PlayerInfo[playerid][TempoAtordoado] = 240; 
    
    MostrarDeathTD(playerid);
    
    NT(playerid, "Voce foi atordoado! Aguarde o SAMU ou espere 4 minutos.", 10, "Aviso");
    return 1;
    #pragma unused killerid, reason
}

public OnPlayerText(playerid, text[])
{
    NT(playerid, "O chat global esta desativado. Use comandos para interagir.", 5, "Erro");
    return 0; 
    #pragma unused text
}

// -----------------------------------------------------------------------
//  Callbacks vazios 
// -----------------------------------------------------------------------

public OnVehicleSpawn(vehicleid)                                    { return 1; }
public OnVehicleDeath(vehicleid, killerid)                          { return 1; }
public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)       { return 1; }
public OnPlayerExitVehicle(playerid, vehicleid)                     { return 1; }
public OnPlayerStateChange(playerid, newstate, oldstate)            { return 1; }
public OnPlayerEnterCheckpoint(playerid)                            { return 1; }
public OnPlayerLeaveCheckpoint(playerid)                            { return 1; }
public OnPlayerEnterRaceCheckpoint(playerid)                        { return 1; }
public OnPlayerLeaveRaceCheckpoint(playerid)                        { return 1; }
public OnRconCommand(cmd[])                                         { return 1; }
public OnPlayerRequestSpawn(playerid)                               { return 1; }
public OnObjectMoved(objectid)                                      { return 1; }
public OnPlayerObjectMoved(playerid, objectid)                      { return 1; }
public OnPlayerPickUpPickup(playerid, pickupid)                     { return 1; }
public OnVehicleMod(playerid, vehicleid, componentid)               { return 1; }
public OnVehiclePaintjob(playerid, vehicleid, paintjobid)           { return 1; }
public OnVehicleRespray(playerid, vehicleid, color1, color2)        { return 1; }
public OnPlayerSelectedMenuRow(playerid, row)                       { return 1; }
public OnPlayerExitedMenu(playerid)                                 { return 1; }
public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid) { return 1; }
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)           { return 1; }
public OnRconLoginAttempt(ip[], password[], success)                { return 1; }
public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(playertextid == INVALID_PLAYER_TEXT_DRAW) return 1;

    if(playertextid == LoginTD[playerid][3]) 
    {
        EsconderLoginTD(playerid);
        MostrarRegistroTD(playerid);
        return 1;
    }

    if(playertextid == LoginTD[playerid][9]) 
    {
        ShowPlayerDialog(playerid, DIALOG_SENHA, DIALOG_STYLE_PASSWORD,
            "[{9281F4}RickZin021{FFFFFF}] Login",
            "Digite sua senha abaixo para entrar:", "Login", "Cancelar");
        return 1;
    }

    if(playertextid == RegTD[playerid][5]) 
    {
        ShowPlayerDialog(playerid, DIALOG_SENHA, DIALOG_STYLE_INPUT,
            "[{9281F4}RickZin021{FFFFFF}] Senha",
            "Crie uma senha segura para sua conta:", "Confirmar", "Cancelar");
        return 1;
    }

    if(playertextid == RegTD[playerid][6]) 
    {
        if(!strlen(VSenha[playerid]))
            return NT(playerid, "Voce precisa definir uma senha primeiro!", 5, "Erro");

        EsconderRegistroTD(playerid);

        ShowPlayerDialog(playerid, DIALOG_GENERO, DIALOG_STYLE_MSGBOX,
            "[{9281F4}RickZin021{FFFFFF}] Genero",
            "Selecione o genero do seu personagem:", "Masculino", "Feminino");
        return 1;
    }

    return 1;
}
public OnPlayerStreamIn(playerid, forplayerid)                      { return 1; }
public OnPlayerStreamOut(playerid, forplayerid)                     { return 1; }
public OnVehicleStreamIn(vehicleid, forplayerid)                    { return 1; }
public OnVehicleStreamOut(vehicleid, forplayerid)                   { return 1; }

// -----------------------------------------------------------------------
//  Sistema de login / registro
// -----------------------------------------------------------------------

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case DIALOG_SENHA:
        {
            if(!response) return Kick(playerid);

            new len = strlen(inputtext);
            if(len < 5 || len > 20)
            {
                NT(playerid, "A senha deve ter entre 5 e 20 caracteres.", 5, "Erro");
                return ShowAuthDialog(playerid);
            }

            if(EstaRegistrado[playerid]) 
            {
                new query[128], DBResult:res;
                format(query, sizeof(query), "SELECT senha FROM players WHERE name = '%s' LIMIT 1", PlayerName(playerid));
                res = db_query(db_handle, query);

                if(res && db_num_rows(res) > 0)
                {
                    new db_pass[20];
                    db_get_field_assoc(res, "senha", db_pass, 20);
                    db_free_result(res);

                    if(!strcmp(inputtext, db_pass, false))
                    {
                        CarregarDadosPlayer(playerid);
                        NT(playerid, "Login efetuado com sucesso!", 5, "Sucesso");
                    }
                    else
                    {
                        TentativasSenha[playerid]++;
                        if(TentativasSenha[playerid] >= 3)
                        {
                            NT(playerid, "Voce errou a senha 3 vezes e foi expulso.", 5, "Erro");
                            SetTimerEx("KickPlayer", 500, false, "i", playerid);
                        }
                        else
                        {
                            new msg[64];
                            format(msg, sizeof(msg), "Senha incorreta! Tentativas: %d/3", TentativasSenha[playerid]);
                            NT(playerid, msg, 5, "Erro");
                            ShowAuthDialog(playerid);
                        }
                    }
                }
            }
            else 
            {
                format(VSenha[playerid], 20, inputtext);
                
                new mask[21];
                for(new i = 0; i < len; i++) mask[i] = '*';
                PlayerTextDrawSetString(playerid, RegTD[playerid][5], mask);
                
                NT(playerid, "Senha definida!", 3, "Sucesso");
            }
        }
        case DIALOG_GENERO:
        {
            VGenero[playerid] = (response ? 0 : 1); 
            CriarDadosPlayer(playerid);
            NT(playerid, "Conta registrada com sucesso!", 5, "Sucesso");
        }
        case DIALOG_BOASVINDAS:
        {
            SpawnPlayerLogado(playerid);
        }
    }
    return 1;
    #pragma unused listitem
}
