/* 
 RickZIn021 
 github: https://github.com/rickcosta-dev 
 repositorio: https://github.com/rickcosta-dev/gamemode-base 
 com licensa apache 2.0 
 */

stock CriarNotifyTD(playerid)
{
    NotifyTD[playerid][0] = CreatePlayerTextDraw(playerid, 400.000000, 150.000000, "_"); 
    PlayerTextDrawLetterSize(playerid, NotifyTD[playerid][0], 0.000000, 2.800000); 
    PlayerTextDrawTextSize(playerid, NotifyTD[playerid][0], 630.000000, 0.000000); 
    PlayerTextDrawAlignment(playerid, NotifyTD[playerid][0], 1); 
    PlayerTextDrawColor(playerid, NotifyTD[playerid][0], -1); 
    PlayerTextDrawUseBox(playerid, NotifyTD[playerid][0], 1); 
    PlayerTextDrawBoxColor(playerid, NotifyTD[playerid][0], 0x00000099); 
    PlayerTextDrawSetShadow(playerid, NotifyTD[playerid][0], 0); 
    PlayerTextDrawSetSelectable(playerid, NotifyTD[playerid][0], 0); 
     
    NotifyTD[playerid][1] = CreatePlayerTextDraw(playerid, 398.000000, 150.000000, "_"); 
    PlayerTextDrawLetterSize(playerid, NotifyTD[playerid][1], 0.000000, 2.800000); 
    PlayerTextDrawTextSize(playerid, NotifyTD[playerid][1], 401.000000, 0.000000); 
    PlayerTextDrawAlignment(playerid, NotifyTD[playerid][1], 1); 
    PlayerTextDrawColor(playerid, NotifyTD[playerid][1], -1); 
    PlayerTextDrawUseBox(playerid, NotifyTD[playerid][1], 1); 
    PlayerTextDrawBoxColor(playerid, NotifyTD[playerid][1], 0x2ECC71FF); 
    PlayerTextDrawSetShadow(playerid, NotifyTD[playerid][1], 0); 
    PlayerTextDrawSetSelectable(playerid, NotifyTD[playerid][1], 0); 
    
    NotifyTD[playerid][2] = CreatePlayerTextDraw(playerid, 407.000000, 157.000000, "BASE RICKZIN021..."); 
    PlayerTextDrawFont(playerid, NotifyTD[playerid][2], 1); 
    PlayerTextDrawLetterSize(playerid, NotifyTD[playerid][2], 0.220000, 1.100000); 
    PlayerTextDrawColor(playerid, NotifyTD[playerid][2], -1); 
    PlayerTextDrawAlignment(playerid, NotifyTD[playerid][2], 1); 
    PlayerTextDrawSetOutline(playerid, NotifyTD[playerid][2], 0); 
    PlayerTextDrawSetShadow(playerid, NotifyTD[playerid][2], 1); 
    PlayerTextDrawSetProportional(playerid, NotifyTD[playerid][2], 1); 
    PlayerTextDrawTextSize(playerid, NotifyTD[playerid][2], 625.000000, 0.000000); 
    PlayerTextDrawSetSelectable(playerid, NotifyTD[playerid][2], 0);
    return 1;
}

stock MostrarNotifyTD(playerid, mensagem[], cor_barra, segundos)
{
    PlayerTextDrawSetString(playerid, NotifyTD[playerid][2], mensagem);
    PlayerTextDrawBoxColor(playerid, NotifyTD[playerid][1], cor_barra);
    
    PlayerTextDrawShow(playerid, NotifyTD[playerid][0]);
    PlayerTextDrawShow(playerid, NotifyTD[playerid][1]);
    PlayerTextDrawShow(playerid, NotifyTD[playerid][2]);
    
    NotifyTimer[playerid] = segundos;
    return 1;
}

stock EsconderNotifyTD(playerid)
{
    PlayerTextDrawHide(playerid, NotifyTD[playerid][0]);
    PlayerTextDrawHide(playerid, NotifyTD[playerid][1]);
    PlayerTextDrawHide(playerid, NotifyTD[playerid][2]);
    NotifyTimer[playerid] = 0;
    return 1;
}
