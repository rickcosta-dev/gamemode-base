/* 
 RickZIn021 
 github: https://github.com/rickcosta-dev 
 repositorio: https://github.com/rickcosta-dev/gamemode-base 
 com licensa apache 2.0 
 */

// -----------------------------------------------------------------------
//  Permissão
// -----------------------------------------------------------------------

stock bool:CheckAdmin(playerid, level)
{
    if(PlayerInfo[playerid][Admin] < level)
    {
        NT(playerid, "Voce não tem permissão para usar este comando.", 5, "Erro");
        return false;
    }
    return true;
}

// =============================================================================
//  Comandos
// =============================================================================

CMD:setadmin(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_FUNDADOR)) return 1;

    new idfixo, nivel;
    if(sscanf(params, "ii", idfixo, nivel)) return NT(playerid, "Uso: /setadmin [IDF] [Nivel 0-8]", 5, "Aviso");
    
    new targetid = GetPlayerByIDF(idfixo);
    if(targetid == INVALID_PLAYER_ID) return NT(playerid, "Jogador com este IDF não está online.", 5, "Erro");
    if(nivel < 0 || nivel > 8) return NT(playerid, "Nivel invalido (0-8).", 5, "Erro");

    PlayerInfo[targetid][Admin] = nivel;
    SalvarDados(targetid);

    new msg[128];
    format(msg, sizeof(msg), "Seu nivel de admin foi definido para %d por %s.", nivel, PlayerName(playerid));
    NT(targetid, msg, 5, "Sucesso");

    format(msg, sizeof(msg), "Admin de %s definido para nivel %d.", PlayerName(targetid), nivel);
    NT(playerid, msg, 5, "Sucesso");
    return 1;
}

CMD:kick(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_MOD)) return 1;

    new idfixo, motivo[64];
    if(sscanf(params, "is[64]", idfixo, motivo)) return NT(playerid, "Uso: /kick [IDF] [Motivo]", 5, "Aviso");

    new targetid = GetPlayerByIDF(idfixo);
    if(targetid == INVALID_PLAYER_ID) return NT(playerid, "Jogador com este IDF não está online.", 5, "Erro");
    if(PlayerInfo[targetid][Admin] >= PlayerInfo[playerid][Admin] && playerid != targetid) 
        return NT(playerid, "Voce nao pode kickar um admin de nivel igual ou superior.", 5, "Erro");

    new msg[144];
    format(msg, sizeof(msg), "{FF0000}[KICK] {FFFFFF}%s foi expulso por %s. Motivo: %s", PlayerName(targetid), PlayerName(playerid), motivo);
    SendClientMessageToAll(-1, msg);
    
    SetTimerEx("KickPlayer", 500, false, "i", targetid);
    return 1;
}

CMD:ir(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_MOD)) return 1;

    new idfixo;
    if(sscanf(params, "i", idfixo)) return NT(playerid, "Uso: /ir [IDF]", 5, "Aviso");

    new targetid = GetPlayerByIDF(idfixo);
    if(targetid == INVALID_PLAYER_ID) return NT(playerid, "Jogador com este IDF não está online.", 5, "Erro");

    new Float:fPos[3];
    GetPlayerPos(targetid, fPos[0], fPos[1], fPos[2]);
    SetPlayerPos(playerid, fPos[0] + 1.0, fPos[1], fPos[2]);
    SetPlayerInterior(playerid, GetPlayerInterior(targetid));
    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(targetid));

    NT(playerid, "Teleportado com sucesso.", 3, "Sucesso");
    return 1;
}

CMD:traz(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_MOD)) return 1;

    new idfixo;
    if(sscanf(params, "i", idfixo)) return NT(playerid, "Uso: /traz [IDF]", 5, "Aviso");

    new targetid = GetPlayerByIDF(idfixo);
    if(targetid == INVALID_PLAYER_ID) return NT(playerid, "Jogador com este IDF não está online.", 5, "Erro");

    new Float:fPos[3];
    GetPlayerPos(playerid, fPos[0], fPos[1], fPos[2]);
    SetPlayerPos(targetid, fPos[0] + 1.0, fPos[1], fPos[2]);
    SetPlayerInterior(targetid, GetPlayerInterior(playerid));
    SetPlayerVirtualWorld(targetid, GetPlayerVirtualWorld(playerid));

    NT(targetid, "Voce foi puxado por um administrador.", 5, "Aviso");
    NT(playerid, "Jogador puxado com sucesso.", 3, "Sucesso");
    return 1;
}

CMD:aviso(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_MOD)) return 1;
    if(isnull(params)) return NT(playerid, "Uso: /aviso [Mensagem]", 5, "Aviso");

    new msg[144];
    format(msg, sizeof(msg), "{FF0000}[AVISO] {FFFFFF}%s: %s", PlayerName(playerid), params);
    SendClientMessageToAll(-1, msg);
    return 1;
}

CMD:dararma(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_ADMIN)) return 1;

    new idfixo, arma, ammo;
    if(sscanf(params, "iii", idfixo, arma, ammo)) return NT(playerid, "Uso: /dararma [IDF] [ID Arma] [Municao]", 5, "Aviso");

    new targetid = GetPlayerByIDF(idfixo);
    if(targetid == INVALID_PLAYER_ID) return NT(playerid, "Jogador com este IDF não está online.", 5, "Erro");
    if(arma < 1 || arma > 46) return NT(playerid, "ID de arma invalido.", 5, "Erro");

    GivePlayerWeapon(targetid, arma, ammo);
    NT(playerid, "Arma entregue.", 5, "Sucesso");
    return 1;
}

CMD:hp(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_MOD)) return 1;

    new targetid;
    if(isnull(params)) targetid = playerid;
    else
    {
        new idfixo = strval(params);
        targetid = GetPlayerByIDF(idfixo);
        if(targetid == INVALID_PLAYER_ID) return NT(playerid, "Jogador com este IDF não está online.", 5, "Erro");
    }

    SetPlayerHealth(targetid, 100.0);
    NT(playerid, "Vida definida para 100.", 5, "Sucesso");
    return 1;
}

CMD:kitadmin(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_MOD)) return 1;

    ResetPlayerWeapons(playerid);
    GivePlayerWeapon(playerid, 24, 500); 
    GivePlayerWeapon(playerid, 31, 1000); 
    SetPlayerHealth(playerid, 100.0);
    SetPlayerArmour(playerid, 100.0);
    NT(playerid, "Kit administrativo equipado.", 5, "Sucesso");
    return 1;
}

CMD:tele(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_MOD)) return 1;

    new Float:x, Float:y, Float:z;
    if(sscanf(params, "fff", x, y, z)) return NT(playerid, "Uso: /tele [X] [Y] [Z]", 5, "Aviso");
    
    SetPlayerPos(playerid, x, y, z);
    NT(playerid, "Teleportado para as coordenadas.", 5, "Sucesso");
    return 1;
}

CMD:id(playerid, params[])
{
    new idfixo;
    if(sscanf(params, "i", idfixo)) return NT(playerid, "Uso: /id [IDF]", 5, "Aviso");
    
    new targetid = GetPlayerByIDF(idfixo);
    if(targetid == INVALID_PLAYER_ID) return NT(playerid, "Jogador com este IDF não está online.", 5, "Erro");
    
    new msg[128];
    format(msg, sizeof(msg), "ID Tab: %d | Nome: %s | Nivel: %d | Admin: %d", targetid, PlayerName(targetid), GetPlayerScore(targetid), PlayerInfo[targetid][Admin]);
    SendClientMessage(playerid, COLOR_WHITE, msg);
    return 1;
}

CMD:cv(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_ADMIN)) return 1;
    
    new model;
    if(sscanf(params, "i", model)) return NT(playerid, "Uso: /cv [ID do Veiculo (400-611)]", 5, "Aviso");
    if(model < 400 || model > 611) return NT(playerid, "ID de veiculo invalido (400-611).", 5, "Erro");

    new Float:fPos[3], Float:fAngle;
    GetPlayerPos(playerid, fPos[0], fPos[1], fPos[2]);
    GetPlayerFacingAngle(playerid, fAngle);

    new veh = CreateVehicle(model, fPos[0], fPos[1], fPos[2], fAngle, -1, -1, 60000);
    PutPlayerInVehicle(playerid, veh, 0);
    
    new msg[64];
    format(msg, sizeof(msg), "Veiculo ID %d criado com sucesso.", model);
    NT(playerid, msg, 5, "Sucesso");
    return 1;
}

// -----------------------------------------------------------------------
//  Menu Administrativo
// -----------------------------------------------------------------------

static stock MostrarAdminMenu(playerid)
{
    new nivel = PlayerInfo[playerid][Admin];

    new titulo[64], cargo[32];
    switch(nivel) {
        case ADMIN_AJUDANTE:    cargo = "Ajudante";
        case ADMIN_MOD:         cargo = "Moderador";
        case ADMIN_ADMIN:       cargo = "Administrador";
        case ADMIN_SUPERVISOR:  cargo = "Supervisor";
        case ADMIN_GERENTE:     cargo = "Gerente";
        case ADMIN_COORDENADOR: cargo = "Coordenador";
        case ADMIN_SUBDONO:     cargo = "Sub Dono";
        case ADMIN_FUNDADOR:    cargo = "Fundador";
        default:                cargo = "Jogador";
    }
    format(titulo, sizeof(titulo), "{9281F4}Painel Admin | %s", cargo);

    new lista[512];
    if(nivel >= ADMIN_AJUDANTE) {
        strcat(lista, "Kit Admin\n");
    }
    if(nivel >= ADMIN_MOD) {
        strcat(lista, "Teleporte (IrPara)\nTrazer (Traz)\nExpulsar (Kick)\n");
    }
    if(nivel >= ADMIN_ADMIN) {
        strcat(lista, "Dar Arma\nCriar Veiculo (/cv)\nAnuncio Global\n");
    }
    if(nivel >= ADMIN_FUNDADOR) {
        strcat(lista, "Definir Admin\n");
    }

    ShowPlayerDialog(playerid, DIALOG_ADMINMENU, DIALOG_STYLE_LIST, titulo, lista, "Selecionar", "Fechar");
    return 1;
}

CMD:adminmenu(playerid, params[])
{
    if(!CheckAdmin(playerid, ADMIN_MOD)) return 1;
    MostrarAdminMenu(playerid);
    return 1;
}

// -----------------------------------------------------------------------
//  IDs de sub-dialogs para o /cv
// -----------------------------------------------------------------------

#define DIALOG_ADMIN_CV (DIALOG_ADMIN_SETADMIN + 1)

stock HandleAdminMenuDialog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new nivel = PlayerInfo[playerid][Admin];
    new item = 0;

    if(nivel >= ADMIN_MOD)
    {
        if(listitem == item++) return ShowPlayerDialog(playerid, DIALOG_ADMIN_GOTO, DIALOG_STYLE_INPUT, "IrPara", "Digite o ID/Nome:", "Ir", "Voltar");
        if(listitem == item++) return ShowPlayerDialog(playerid, DIALOG_ADMIN_GETHERE, DIALOG_STYLE_INPUT, "Traz", "Digite o ID/Nome:", "Puxar", "Voltar");
        if(listitem == item++) return ShowPlayerDialog(playerid, DIALOG_ADMIN_KICK, DIALOG_STYLE_INPUT, "Kick", "Digite ID/Nome e Motivo:", "Kick", "Voltar");
        if(listitem == item++) return ShowPlayerDialog(playerid, DIALOG_ADMIN_DARARMA, DIALOG_STYLE_INPUT, "Dar Arma", "Digite ID/Nome, Arma e Municao:", "Dar", "Voltar");
        if(listitem == item++) { cmd_kitadmin(playerid, ""); return MostrarAdminMenu(playerid); }
    }

    if(nivel >= ADMIN_ADMIN)
    {
        if(listitem == item++) return ShowPlayerDialog(playerid, DIALOG_ADMIN_CV, DIALOG_STYLE_INPUT, "Criar Veiculo", "Digite o ID do Veiculo (400-611):", "Criar", "Voltar");
        if(listitem == item++) return ShowPlayerDialog(playerid, DIALOG_ADMIN_ANN, DIALOG_STYLE_INPUT, "Anuncio", "Digite a mensagem:", "Enviar", "Voltar");
    }

    if(nivel >= ADMIN_FUNDADOR)
    {
        if(listitem == item++) return ShowPlayerDialog(playerid, DIALOG_ADMIN_SETADMIN, DIALOG_STYLE_INPUT, "SetAdmin", "Digite ID/Nome e Nivel (0-8):", "Definir", "Voltar");
    }

    return 1;
    #pragma unused inputtext
}
