/* 
 RickZIn021 
 github: https://github.com/rickcosta-dev 
 repositorio: https://github.com/rickcosta-dev/gamemode-base 
 com licensa apache 2.0 
 */

// -----------------------------------------------------------------------
//  Retorna o nome do player como string
// -----------------------------------------------------------------------

stock PlayerName(playerid)
{
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    return name;
}

// -----------------------------------------------------------------------
//  Envia N linhas em branco para limpar o chat do player
// -----------------------------------------------------------------------

stock LimparChat(playerid, linhas)
{
    for(new i = 0; i < linhas; i++)
        SendClientMessage(playerid, -1, "");
}

// -----------------------------------------------------------------------
//  Notificação simples
// -----------------------------------------------------------------------

stock NT(playerid, mensagem[], tempo = 5, tipo[] = "Aviso")
{
    new color_barra;
    if(!strcmp(tipo, "Erro", true)) color_barra = 0xE74C3CFF;
    else if(!strcmp(tipo, "Sucesso", true)) color_barra = 0x2ECC71FF;
    else if(!strcmp(tipo, "Aviso", true)) color_barra = 0xF1C40FFF;
    else color_barra = 0x3498DBFF;

    MostrarNotifyTD(playerid, mensagem, color_barra, tempo);
    return 1;
}

// -----------------------------------------------------------------------
//  Busca player pelo IDF
// -----------------------------------------------------------------------

stock GetPlayerByIDF(idfixo)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i) && VerificarLogin[i] && PlayerInfo[i][IDF] == idfixo)
            return i;
    }
    return INVALID_PLAYER_ID;
}

// -----------------------------------------------------------------------
//  Verifica se uma string é numérica
// -----------------------------------------------------------------------

stock IsNumeric(const string[])
{
    for (new i = 0, j = strlen(string); i < j; i++)
    {
        if (string[i] > '9' || string[i] < '0') return 0;
    }
    return 1;
}
