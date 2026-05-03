/* 
 RickZIn021 
 github: https://github.com/rickcosta-dev 
 repositorio: https://github.com/rickcosta-dev/gamemode-base 
 com licensa apache 2.0 
 */

// -----------------------------------------------------------------------
//  Configurações SQLite
// -----------------------------------------------------------------------

#define DB_NAME             "database.db"

new DB:db_handle;

// -----------------------------------------------------------------------
//  Cores
// -----------------------------------------------------------------------

#define COLOR_SERVER        (0xFFFF90FF)
#define COLOR_CLIENT        (0xAAC4E5FF)
#define COLOR_WHITE         (0xFFFFFFFF)
#define COLOR_RED           (0xFF0000FF)
#define COLOR_GREEN         (0x33CC33FF)
#define COLOR_YELLOW        (0xFFFF00FF)
#define COLOR_ORANGE        (0xFFA500FF)
#define COLOR_GREY          (0xAFAFAFFF)
#define COLOR_PURPLE        (0xD0AEEBFF)
#define COLOR_BLUE          (0x2641FEFF)
#define COLOR_CYAN          (0x33CCFFFF)
#define COLOR_LIME          (0x00FF00FF)
#define COLOR_DARKBLUE      (0x1394BFFF)
#define COLOR_ADMIN         (0xFF8282FF)

// -----------------------------------------------------------------------
//  Textdraws
// -----------------------------------------------------------------------

#define INVALID_PLAYER_TEXT_DRAW (PlayerText:65535)

// -----------------------------------------------------------------------
//  Niveis de administracao
// -----------------------------------------------------------------------

#define ADMIN_AJUDANTE      1
#define ADMIN_MOD           2
#define ADMIN_ADMIN         3
#define ADMIN_SUPERVISOR    4
#define ADMIN_GERENTE       5
#define ADMIN_COORDENADOR   6
#define ADMIN_SUBDONO       7
#define ADMIN_FUNDADOR      8

#define IsAdmin(%0,%1)      (PlayerInfo[%0][Admin] >= %1)

// -----------------------------------------------------------------------
//  dialogs
// -----------------------------------------------------------------------

enum
{
    DIALOG_SENHA,
    DIALOG_GENERO,
    DIALOG_BOASVINDAS,
    DIALOG_ADMINMENU,
    DIALOG_ADMIN_KICK,
    DIALOG_ADMIN_ANN,
    DIALOG_ADMIN_GOTO,
    DIALOG_ADMIN_GETHERE,
    DIALOG_ADMIN_DARARMA,
    DIALOG_ADMIN_SETADMIN
};

// -----------------------------------------------------------------------
//  Dados do player
// -----------------------------------------------------------------------

enum pInfo
{
    Name[MAX_PLAYER_NAME],
    IP[16],
    Senha[20],
    IDF,
    Dinheiro,
    Level,
    Skin,
    Genero,
    Admin,
    Interior,
    VirtualW,
    Float:VidaHP,
    Float:ColeteHP,
    Float:PosX,
    Float:PosY,
    Float:PosZ,
    Float:PosR,
    Atordoado,
    TempoAtordoado
};

// -----------------------------------------------------------------------
//  Variaveis globais
// -----------------------------------------------------------------------

new PlayerInfo[MAX_PLAYERS][pInfo];

new VSenha[MAX_PLAYERS][20];
new VGenero[MAX_PLAYERS];
new TentativasSenha[MAX_PLAYERS];

new bool:VerificarLogin[MAX_PLAYERS];
new bool:EstaRegistrado[MAX_PLAYERS];
new bool:AguardandoBV[MAX_PLAYERS];

new PlayerText:NotifyTD[MAX_PLAYERS][3];
new PlayerText:LoginTD[MAX_PLAYERS][11];
new PlayerText:RegTD[MAX_PLAYERS][7];
new PlayerText:LoadTD[MAX_PLAYERS][6];
new NotifyTimer[MAX_PLAYERS];
new LoadProgress[MAX_PLAYERS];

#pragma unused PlayerInfo, VSenha, VGenero, TentativasSenha, NotifyTD, NotifyTimer, LoginTD, RegTD, LoadTD, LoadProgress
#pragma unused VerificarLogin, EstaRegistrado, AguardandoBV

#pragma warning enable 203
