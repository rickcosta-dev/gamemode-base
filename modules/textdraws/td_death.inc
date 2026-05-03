/* 
 RickZIn021 
 github: https://github.com/rickcosta-dev 
 repositorio: https://github.com/rickcosta-dev/gamemode-base 
 com licensa apache 2.0 
 */

new PlayerText:DeathTD[MAX_PLAYERS][6];

stock CriarDeathTD(playerid)
{
    DeathTD[playerid][0] = CreatePlayerTextDraw(playerid, 320.000000, 0.000000, "_");
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][0], 2);
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][0], 0.000000, 50.000000);
    PlayerTextDrawTextSize(playerid, DeathTD[playerid][0], 0.000000, 640.000000);
    PlayerTextDrawUseBox(playerid, DeathTD[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, DeathTD[playerid][0], 0x000000AA); 

    DeathTD[playerid][1] = CreatePlayerTextDraw(playerid, 320.000000, 185.000000, "_");
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][1], 2);
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][1], 0.000000, 7.500000);
    PlayerTextDrawTextSize(playerid, DeathTD[playerid][1], 0.000000, 640.000000);
    PlayerTextDrawUseBox(playerid, DeathTD[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, DeathTD[playerid][1], 0x00BFFFFF); 

    DeathTD[playerid][2] = CreatePlayerTextDraw(playerid, 320.000000, 185.000000, "_");
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][2], 2);
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][2], 0.000000, 0.100000);
    PlayerTextDrawTextSize(playerid, DeathTD[playerid][2], 0.000000, 640.000000);
    PlayerTextDrawUseBox(playerid, DeathTD[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, DeathTD[playerid][2], -1); 

    DeathTD[playerid][3] = CreatePlayerTextDraw(playerid, 320.000000, 195.000000, "VOCE ESTA ATORDOADO");
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][3], 2);
    PlayerTextDrawFont(playerid, DeathTD[playerid][3], 3); 
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][3], 0.600000, 3.200000); 
    PlayerTextDrawColor(playerid, DeathTD[playerid][3], -1); 
    PlayerTextDrawSetOutline(playerid, DeathTD[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][3], 0);

    DeathTD[playerid][4] = CreatePlayerTextDraw(playerid, 320.000000, 232.000000, "AGUARDE O SAMU CHEGAR... CASO CONTRARIO, SERA LEVADO AO HOSPITAL.");
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][4], 2);
    PlayerTextDrawFont(playerid, DeathTD[playerid][4], 1);
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][4], 0.180000, 0.950000);
    PlayerTextDrawColor(playerid, DeathTD[playerid][4], 0xFFFFFFFF);
    PlayerTextDrawSetShadow(playerid, DeathTD[playerid][4], 1);

    DeathTD[playerid][5] = CreatePlayerTextDraw(playerid, 320.000000, 252.000000, "_");
    PlayerTextDrawAlignment(playerid, DeathTD[playerid][5], 2);
    PlayerTextDrawLetterSize(playerid, DeathTD[playerid][5], 0.000000, 0.100000);
    PlayerTextDrawTextSize(playerid, DeathTD[playerid][5], 0.000000, 640.000000);
    PlayerTextDrawUseBox(playerid, DeathTD[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, DeathTD[playerid][5], -1);
    return 1;
}

stock MostrarDeathTD(playerid)
{
    for(new i = 0; i < 6; i++) PlayerTextDrawShow(playerid, DeathTD[playerid][i]);
    return 1;
}

stock EsconderDeathTD(playerid)
{
    for(new i = 0; i < 6; i++) PlayerTextDrawHide(playerid, DeathTD[playerid][i]);
    return 1;
}
