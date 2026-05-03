/* 
 RickZIn021 
 github: https://github.com/rickcosta-dev 
 repositorio: https://github.com/rickcosta-dev/gamemode-base 
 com licensa apache 2.0 
 */

// -----------------------------------------------------------------------
//  Timers gerais
// -----------------------------------------------------------------------

forward KickPlayer(playerid);
public KickPlayer(playerid)
{
    Kick(playerid);
    return 1;
}

forward UmSegundo();
public UmSegundo()
{
    foreach(new i : Player)
    {
        if(!VerificarLogin[i])
            LimparChat(i, 10);
            
        if(NotifyTimer[i] > 0)
        {
            if(--NotifyTimer[i] == 0)
                EsconderNotifyTD(i);
        }

        if(PlayerInfo[i][Atordoado] && PlayerInfo[i][TempoAtordoado] > 0)
        {
            PlayerInfo[i][TempoAtordoado]--;

            ApplyAnimation(i, "PED", "FLOOR_hit_f", 4.1, 0, 1, 1, 1, 0, 1);

            new str[128], minutos, segundos;
            minutos = PlayerInfo[i][TempoAtordoado] / 60;
            segundos = PlayerInfo[i][TempoAtordoado] % 60;

            format(str, sizeof(str), "AGUARDE O SAMU... CASO CONTRARIO, HP EM: %02d:%02d", minutos, segundos);
            PlayerTextDrawSetString(i, DeathTD[i][4], str);

            if(PlayerInfo[i][TempoAtordoado] <= 0)
            {
                PlayerInfo[i][Atordoado] = 0;
                EsconderDeathTD(i);
                TogglePlayerControllable(i, true);
                ClearAnimations(i);
                
                PlayerInfo[i][PosX] = 1172.9332;
                PlayerInfo[i][PosY] = -1323.3262;
                PlayerInfo[i][PosZ] = 15.4032;
                PlayerInfo[i][PosR] = 270.0;
                
                SpawnPlayer(i); 
                NT(i, "O SAMU nao chegou e voce foi levado ao Hospital!", 5, "Aviso");
            }
        }
    }
    return 1;
}

forward IDCarregando(playerid);
public IDCarregando(playerid)
{
    new str[64];
    format(str, sizeof(str), "%s [%d]", PlayerName(playerid), PlayerInfo[playerid][IDF]);
    SetPlayerChatBubble(playerid, str, COLOR_WHITE, 20.0, 600000); 
    return 1;
}

forward Descongelar(playerid);
public Descongelar(playerid)
{
    TogglePlayerControllable(playerid, true);
    DeletePVar(playerid, "Frozen");
    return 1;
}

forward UpdateLoading(playerid);
public UpdateLoading(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    LoadProgress[playerid] += 5; 
    
    new Float:progress_width = 220.0 + (float(LoadProgress[playerid]) * 2.0);
    PlayerTextDrawTextSize(playerid, LoadTD[playerid][4], progress_width, 0.000000);
    PlayerTextDrawShow(playerid, LoadTD[playerid][4]); 
    
    if(LoadProgress[playerid] >= 100)
    {
        EsconderLoadScreen(playerid);
        ShowAuthDialog(playerid);
    }
    return 1;
}
