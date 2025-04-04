
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 5;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 5;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 0;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */

static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]               = { 
  "JetBrains Mono:size=11:style=Bold", 
  "HackNerdFont:size=12"
};
static const char dmenufont[]            = "JetBrains Mono:size=14:style=Bold";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#fff8e6";
static char normbgcolor[]                = "#282828";
static char normbordercolor[]            = "#3c3836";
static char normfloatcolor[]             = "#a73b3b";

static char selfgcolor[]                 = "#fff8e6";
static char selbgcolor[]                 = "#8f0000";
static char selbordercolor[]             = "#8f0000";
static char selfloatcolor[]              = "#8f0000";

static char titlenormfgcolor[]           = "#fff8e6";
static char titlenormbgcolor[]           = "#282828";
static char titlenormbordercolor[]       = "#3c3836";
static char titlenormfloatcolor[]        = "#3c3836";

static char titleselfgcolor[]            = "#fff8e6";
static char titleselbgcolor[]            = "#8f0000";
static char titleselbordercolor[]        = "#8f0000";
static char titleselfloatcolor[]         = "#8f0000";

static char tagsnormfgcolor[]            = "#fff8e6";
static char tagsnormbgcolor[]            = "#282828";
static char tagsnormbordercolor[]        = "#3c3836";
static char tagsnormfloatcolor[]         = "#3c3836";

static char tagsselfgcolor[]             = "#fff8e6";
static char tagsselbgcolor[]             = "#8f0000";
static char tagsselbordercolor[]         = "#8f0000";
static char tagsselfloatcolor[]          = "#8f0000";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#a73b3b";

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

static const Rule rules[] = {
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "feh", .isfloating = 1)
	RULE(.class = "mpv", .isfloating = 1)
};

static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_status,            NULL,                    "status" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,                    "awesomebar" },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#include <X11/XF86keysym.h>
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};

static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ Mod1Mask,                     XK_F3,         spawn,                  {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = (const char*[]){ "kitty", NULL } } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY|ControlMask,           XK_z,          showhideclient,         {0} },
	{ MODKEY|ShiftMask,             XK_c,          killclient,             {0} },
	{ MODKEY|ShiftMask|ControlMask, XK_q,          quit,                   {0} },
	{ MODKEY|ShiftMask,             XK_r,          quit,                   {1} },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY|ShiftMask,             XK_v,          togglefloating,         {0} },
	{ MODKEY,             			XK_e,          spawn,         		   {.v = (const char *[]){ "thunar", NULL } } },
	{ MODKEY,             			XK_n,          spawn,         		   SHCMD("if [[ $(dunstctl get-pause-level) -eq 0 ]]; then notify-send -a notifier 'notifications will be disabled' -t 1000; sleep 1s; dunstctl set-paused toggle; else dunstctl set-paused toggle; notify-send -a notifier 'notifications enabled' -t 1000; fi; pkill -RTMIN+1 dwmblocks") },
	{ MODKEY,             			XK_w,          spawn,         		   SHCMD("~/.config/dwm/dwm/scripts/weather") },
	{ MODKEY,             			XK_c,          spawn,         		   {.v = (const char *[]){ "clipmenu", NULL } } },
	
  /* custom  */
	{ 0,                            XF86XK_AudioMute,           spawn,          SHCMD("~/.config/dwm/dwm/scripts/audio mute") },
	{ 0,                            XF86XK_AudioLowerVolume,    spawn,          SHCMD("~/.config/dwm/dwm/scripts/audio down") },
    { 0,                            XF86XK_AudioRaiseVolume,    spawn,          SHCMD("~/.config/dwm/dwm/scripts/audio up") },
    { 0,                            XF86XK_MonBrightnessUp,     spawn,          SHCMD("~/.config/dwm/dwm/scripts/brightness up") },
    { 0,                            XF86XK_MonBrightnessDown,   spawn,          SHCMD("~/.config/dwm/dwm/scripts/brightness down") },
	{ ShiftMask,                    XF86XK_AudioLowerVolume,    spawn,          SHCMD("~/.config/dwm/dwm/scripts/audio down fine") },
    { ShiftMask,                    XF86XK_AudioRaiseVolume,    spawn,          SHCMD("~/.config/dwm/dwm/scripts/audio up fine") },
    { ShiftMask,                    XF86XK_MonBrightnessUp,     spawn,          SHCMD("~/.config/dwm/dwm/scripts/brightness up fine") },
    { ShiftMask,                    XF86XK_MonBrightnessDown,   spawn,          SHCMD("~/.config/dwm/dwm/scripts/brightness down fine") },
    { 0,                            XK_Print,                   spawn,          {.v = (const char *[]){ "flameshot", "gui", NULL } } },
    { 0,                            XK_ISO_Next_Group,          spawn,          SHCMD("pkill -RTMIN+10 dwmblocks") },

    TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};

static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};
