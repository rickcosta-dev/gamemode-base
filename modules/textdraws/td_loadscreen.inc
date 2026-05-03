/* 
 RickZIn021 
 github: https://github.com/rickcosta-dev 
 repositorio: https://github.com/rickcosta-dev/gamemode-base 
 com licensa apache 2.0 
 */

stock CriarLoadTD(playerid)
{
    LoadTD[playerid][0] = CreatePlayerTextDraw(playerid, 320.000000, 0.000000, "_");
    PlayerTextDrawAlignment(playerid, LoadTD[playerid][0], 2);
    PlayerTextDrawLetterSize(playerid, LoadTD[playerid][0], 0.000000, 50.000000); 
    PlayerTextDrawTextSize(playerid, LoadTD[playerid][0], 0.000000, 640.000000); 
    PlayerTextDrawUseBox(playerid, LoadTD[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, LoadTD[playerid][0], 0x000000FF); 

    LoadTD[playerid][1] = CreatePlayerTextDraw(playerid, 320.000000, 190.000000, "BASE RICKZIN021");
    PlayerTextDrawAlignment(playerid, LoadTD[playerid][1], 2);
    PlayerTextDrawFont(playerid, LoadTD[playerid][1], 2); 
    PlayerTextDrawLetterSize(playerid, LoadTD[playerid][1], 0.600000, 2.500000);
    PlayerTextDrawColor(playerid, LoadTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, LoadTD[playerid][1], 0);

    LoadTD[playerid][2] = CreatePlayerTextDraw(playerid, 320.000000, 220.000000, "VERSAO 1.0");
    PlayerTextDrawAlignment(playerid, LoadTD[playerid][2], 2);
    PlayerTextDrawFont(playerid, LoadTD[playerid][2], 1);
    PlayerTextDrawLetterSize(playerid, LoadTD[playerid][2], 0.150000, 0.900000);
    PlayerTextDrawColor(playerid, LoadTD[playerid][2], 0x00BFFFFF); 

    LoadTD[playerid][3] = CreatePlayerTextDraw(playerid, 320.000000, 380.000000, "_");
    PlayerTextDrawAlignment(playerid, LoadTD[playerid][3], 2);
    PlayerTextDrawLetterSize(playerid, LoadTD[playerid][3], 0.000000, 0.400000);
    PlayerTextDrawTextSize(playerid, LoadTD[playerid][3], 0.000000, 200.000000); 
    PlayerTextDrawUseBox(playerid, LoadTD[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, LoadTD[playerid][3], 0x333333FF);

    LoadTD[playerid][4] = CreatePlayerTextDraw(playerid, 220.000000, 380.000000, "_"); 
    PlayerTextDrawLetterSize(playerid, LoadTD[playerid][4], 0.000000, 0.400000);
    PlayerTextDrawTextSize(playerid, LoadTD[playerid][4], 220.000000, 0.000000); 
    PlayerTextDrawUseBox(playerid, LoadTD[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, LoadTD[playerid][4], 0x00BFFFFF); 

    LoadTD[playerid][5] = CreatePlayerTextDraw(playerid, 320.000000, 390.000000, "CARREGANDO RECURSOS...");
    PlayerTextDrawAlignment(playerid, LoadTD[playerid][5], 2);
    PlayerTextDrawFont(playerid, LoadTD[playerid][5], 1);
    PlayerTextDrawLetterSize(playerid, LoadTD[playerid][5], 0.140000, 0.800000);
    PlayerTextDrawColor(playerid, LoadTD[playerid][5], -1);
    return 1;
}

stock MostrarLoadScreen(playerid)
{
    LoadProgress[playerid] = 0;
    PlayerTextDrawTextSize(playerid, LoadTD[playerid][4], 220.000000, 0.000000);
    
    for(new i = 0; i < 6; i++) PlayerTextDrawShow(playerid, LoadTD[playerid][i]);
    
    SetTimerEx("UpdateLoading", 100, false, "i", playerid);
    return 1;
}

stock EsconderLoadScreen(playerid)
{
    for(new i = 0; i < 6; i++) PlayerTextDrawHide(playerid, LoadTD[playerid][i]);
    LoadProgress[playerid] = 0;
    return 1;
}
