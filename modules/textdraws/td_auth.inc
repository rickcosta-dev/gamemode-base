/* 
 RickZIn021 
 github: https://github.com/rickcosta-dev 
 repositorio: https://github.com/rickcosta-dev/gamemode-base 
 com licensa apache 2.0 
 */

stock CriarAuthTD(playerid)
{
	// PAINEL LOGIN
	LoginTD[playerid][0] = CreatePlayerTextDraw(playerid, 235.000000, 150.000000, "_");
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][0], 0.000000, 24.000000);
	PlayerTextDrawTextSize(playerid, LoginTD[playerid][0], 345.000000, 0.000000);
	PlayerTextDrawUseBox(playerid, LoginTD[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, LoginTD[playerid][0], 0x000000BB);

	LoginTD[playerid][1] = CreatePlayerTextDraw(playerid, 235.000000, 150.000000, "_");
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][1], 0.000000, 1.800000);
	PlayerTextDrawTextSize(playerid, LoginTD[playerid][1], 345.000000, 0.000000);
	PlayerTextDrawUseBox(playerid, LoginTD[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, LoginTD[playerid][1], 0x00BFFFFF);

	LoginTD[playerid][2] = CreatePlayerTextDraw(playerid, 290.000000, 230.000000, "NAO TEM UMA CONTA?~n~REGISTRE-SE AGORA MESMO");
	PlayerTextDrawAlignment(playerid, LoginTD[playerid][2], 2);
	PlayerTextDrawFont(playerid, LoginTD[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][2], 0.220000, 1.100000);
	PlayerTextDrawColor(playerid, LoginTD[playerid][2], -1);

	LoginTD[playerid][3] = CreatePlayerTextDraw(playerid, 255.000000, 270.000000, "CRIAR CONTA >>>");
	PlayerTextDrawFont(playerid, LoginTD[playerid][3], 2);
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][3], 0.250000, 1.400000);
	PlayerTextDrawUseBox(playerid, LoginTD[playerid][3], 1);
	PlayerTextDrawBoxColor(playerid, LoginTD[playerid][3], 0x00BFFFFF);
	PlayerTextDrawTextSize(playerid, LoginTD[playerid][3], 325.000000, 15.000000);
	PlayerTextDrawSetSelectable(playerid, LoginTD[playerid][3], 1);

	LoginTD[playerid][4] = CreatePlayerTextDraw(playerid, 350.000000, 150.000000, "_");
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][4], 0.000000, 24.000000);
	PlayerTextDrawTextSize(playerid, LoginTD[playerid][4], 460.000000, 0.000000);
	PlayerTextDrawUseBox(playerid, LoginTD[playerid][4], 1);
	PlayerTextDrawBoxColor(playerid, LoginTD[playerid][4], 0x000000BB);

	LoginTD[playerid][5] = CreatePlayerTextDraw(playerid, 350.000000, 150.000000, "_");
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][5], 0.000000, 1.800000);
	PlayerTextDrawTextSize(playerid, LoginTD[playerid][5], 460.000000, 0.000000);
	PlayerTextDrawUseBox(playerid, LoginTD[playerid][5], 1);
	PlayerTextDrawBoxColor(playerid, LoginTD[playerid][5], 0x00BFFFFF);

	LoginTD[playerid][6] = CreatePlayerTextDraw(playerid, 360.000000, 195.000000, "JA TEM UMA CONTA?~n~EFETUE LOGIN");
	PlayerTextDrawFont(playerid, LoginTD[playerid][6], 2);
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][6], 0.240000, 1.200000);
	PlayerTextDrawColor(playerid, LoginTD[playerid][6], -1);

	LoginTD[playerid][7] = CreatePlayerTextDraw(playerid, 360.000000, 240.000000, "SEU NICK:");
	PlayerTextDrawFont(playerid, LoginTD[playerid][7], 1);
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][7], 0.150000, 0.800000);

	LoginTD[playerid][8] = CreatePlayerTextDraw(playerid, 360.000000, 250.000000, "NICKNAME");
	PlayerTextDrawFont(playerid, LoginTD[playerid][8], 1);
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][8], 0.200000, 1.200000);
	PlayerTextDrawTextSize(playerid, LoginTD[playerid][8], 450.000000, 0.000000);
	PlayerTextDrawUseBox(playerid, LoginTD[playerid][8], 1);
	PlayerTextDrawBoxColor(playerid, LoginTD[playerid][8], 0x00BFFFFF);
    PlayerTextDrawColor(playerid, LoginTD[playerid][8], -1); 

	LoginTD[playerid][9] = CreatePlayerTextDraw(playerid, 375.000000, 310.000000, "LOGIN >>>");
	PlayerTextDrawFont(playerid, LoginTD[playerid][9], 2);
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][9], 0.280000, 1.500000);
	PlayerTextDrawUseBox(playerid, LoginTD[playerid][9], 1);
	PlayerTextDrawBoxColor(playerid, LoginTD[playerid][9], 0x00BFFFFF);
	PlayerTextDrawTextSize(playerid, LoginTD[playerid][9], 435.000000, 18.000000);
	PlayerTextDrawSetSelectable(playerid, LoginTD[playerid][9], 1);

	LoginTD[playerid][10] = CreatePlayerTextDraw(playerid, 320.000000, 400.000000, "GameMode Base RickZin021 - Base para estudos.");
	PlayerTextDrawAlignment(playerid, LoginTD[playerid][10], 2);
	PlayerTextDrawFont(playerid, LoginTD[playerid][10], 1);
	PlayerTextDrawLetterSize(playerid, LoginTD[playerid][10], 0.200000, 1.000000);
	PlayerTextDrawColor(playerid, LoginTD[playerid][10], 0xAAAAAAFF);

	// PAINEL REGISTRO
	RegTD[playerid][0] = CreatePlayerTextDraw(playerid, 320.000000, 120.000000, "_");
	PlayerTextDrawAlignment(playerid, RegTD[playerid][0], 2);
	PlayerTextDrawLetterSize(playerid, RegTD[playerid][0], 0.000000, 22.000000);
	PlayerTextDrawTextSize(playerid, RegTD[playerid][0], 0.000000, 280.000000);
	PlayerTextDrawUseBox(playerid, RegTD[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, RegTD[playerid][0], 0x000000CC);

	RegTD[playerid][1] = CreatePlayerTextDraw(playerid, 320.000000, 120.000000, "_");
	PlayerTextDrawAlignment(playerid, RegTD[playerid][1], 2);
	PlayerTextDrawLetterSize(playerid, RegTD[playerid][1], 0.000000, 1.600000);
	PlayerTextDrawTextSize(playerid, RegTD[playerid][1], 0.000000, 280.000000);
	PlayerTextDrawUseBox(playerid, RegTD[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, RegTD[playerid][1], 0x00BFFFFF);

	RegTD[playerid][2] = CreatePlayerTextDraw(playerid, 320.000000, 121.000000, "CADASTRO DE NOVA CONTA");
	PlayerTextDrawAlignment(playerid, RegTD[playerid][2], 2);
	PlayerTextDrawFont(playerid, RegTD[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, RegTD[playerid][2], 0.220000, 1.100000);
	PlayerTextDrawColor(playerid, RegTD[playerid][2], -1);

	RegTD[playerid][3] = CreatePlayerTextDraw(playerid, 320.000000, 150.000000, "Bem-vindo ao RickZin021!~n~Por favor, preencha os dados abaixo para continuar.");
	PlayerTextDrawAlignment(playerid, RegTD[playerid][3], 2);
	PlayerTextDrawFont(playerid, RegTD[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, RegTD[playerid][3], 0.160000, 0.850000);
	PlayerTextDrawColor(playerid, RegTD[playerid][3], 0xCCCCCCFF);

	RegTD[playerid][4] = CreatePlayerTextDraw(playerid, 320.000000, 190.000000, "DIGITE SUA SENHA:");
	PlayerTextDrawAlignment(playerid, RegTD[playerid][4], 2);
	PlayerTextDrawFont(playerid, RegTD[playerid][4], 1);
	PlayerTextDrawLetterSize(playerid, RegTD[playerid][4], 0.180000, 0.900000);
	PlayerTextDrawColor(playerid, RegTD[playerid][4], -1);

	RegTD[playerid][5] = CreatePlayerTextDraw(playerid, 320.000000, 205.000000, "Clique para digitar...");
	PlayerTextDrawAlignment(playerid, RegTD[playerid][5], 2);
	PlayerTextDrawFont(playerid, RegTD[playerid][5], 1);
	PlayerTextDrawLetterSize(playerid, RegTD[playerid][5], 0.200000, 1.200000);
	PlayerTextDrawUseBox(playerid, RegTD[playerid][5], 1);
	PlayerTextDrawBoxColor(playerid, RegTD[playerid][5], 0x333333FF);
	PlayerTextDrawTextSize(playerid, RegTD[playerid][5], 15.000000, 180.000000);
	PlayerTextDrawSetSelectable(playerid, RegTD[playerid][5], 1);

	RegTD[playerid][6] = CreatePlayerTextDraw(playerid, 320.000000, 260.000000, "FINALIZAR CADASTRO");
	PlayerTextDrawAlignment(playerid, RegTD[playerid][6], 2);
	PlayerTextDrawFont(playerid, RegTD[playerid][6], 2);
	PlayerTextDrawLetterSize(playerid, RegTD[playerid][6], 0.250000, 1.400000);
	PlayerTextDrawUseBox(playerid, RegTD[playerid][6], 1);
	PlayerTextDrawBoxColor(playerid, RegTD[playerid][6], 0x2ECC71FF);
	PlayerTextDrawTextSize(playerid, RegTD[playerid][6], 20.000000, 180.000000);
	PlayerTextDrawSetSelectable(playerid, RegTD[playerid][6], 1);
    return 1;
}

stock MostrarLoginTD(playerid)
{
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    
    PlayerTextDrawSetString(playerid, LoginTD[playerid][8], name);

    for(new i = 0; i < 11; i++) PlayerTextDrawShow(playerid, LoginTD[playerid][i]);
    SelectTextDraw(playerid, 0x00BFFFFF);
    return 1;
}

stock EsconderLoginTD(playerid)
{
    for(new i = 0; i < 11; i++) PlayerTextDrawHide(playerid, LoginTD[playerid][i]);
    CancelSelectTextDraw(playerid);
    return 1;
}

stock MostrarRegistroTD(playerid)
{
    for(new i = 0; i < 7; i++) PlayerTextDrawShow(playerid, RegTD[playerid][i]);
    SelectTextDraw(playerid, 0x00BFFFFF);
    return 1;
}

stock EsconderRegistroTD(playerid)
{
    for(new i = 0; i < 7; i++) PlayerTextDrawHide(playerid, RegTD[playerid][i]);
    CancelSelectTextDraw(playerid);
    return 1;
}
