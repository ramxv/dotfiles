/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int gappih = 5;   /* horiz inner gap between windows */
static const unsigned int gappiv = 5;   /* vert inner gap between windows */
static const unsigned int gappoh =
    5; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov =
    5; /* vert outer gap between windows and screen edge */
static const int smartgaps =
    0; /* 1 means no outer gap when there is only one window */
static const int showbar = 1; /* 0 means no bar */
static const int topbar = 1;  /* 0 means bottom bar */
static const char *fonts[] = {
    "TX-02:pixelsize=14:antialias=true:autohint=true",
};
    static const char dmenufont[] = "TX-02:pixelsize=14";
static const char col_gray1[] = "#090E13"; //
static const char col_gray2[] = "#83C092"; //
static const char col_gray3[] = "#eeeeee"; //
static const char col_gray4[] = "#eeeeee"; //
static const char col_cyan[] = "#83C092";  //
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray1, col_gray2, col_cyan},
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT                                                           \
  1 /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"[M]", monocle},
    {"[@]", spiral},
    {"[\\]", dwindle},
    {"H[]", deck},
    {"TTT", bstack},
    {"===", bstackhoriz},
    {"HHH", grid},
    {"###", nrowgrid},
    {"---", horizgrid},
    {":::", gaplessgrid},
    {"|M|", centeredmaster},
    {">M>", centeredfloatingmaster},
    {"><>", NULL}, /* no layout function means floating behavior */
    {NULL, NULL},

};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */

static const char *dmenucmd[] = {
    "dmenu_run", "-m",  dmenumon,  "-fn", dmenufont, "-nb", col_gray1, "-nf",
    col_gray3,   "-sb", col_gray2, "-sf", col_gray1, NULL};
static const char *termcmd[] = {"alacritty", NULL};
static const char *brave[] = {"brave", NULL};
static const char *volup[] = {
    "/bin/sh", "-c", "amixer set Master 5%+ && kill -44 $(pidof dwmblocks)",
    NULL};
static const char *voldown[] = {
    "/bin/sh", "-c", "amixer set Master 5%- && kill -44 $(pidof dwmblocks)",
    NULL};
static const char *volmute[] = {
    "/bin/sh", "-c", "amixer set Master toggle && kill -44 $(pidof dwmblocks)",
    NULL};
static const char *brightup[] = {"/bin/sh", "-c", "brightnessctl set 5%+",
                                 NULL};
static const char *brightdown[] = {"/bin/sh", "-c", "brightnessctl set 5%-",
                                   NULL};

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {0, XF86XK_AudioRaiseVolume, spawn, {.v = volup}},
    {0, XF86XK_AudioLowerVolume, spawn, {.v = voldown}},
    {0, XF86XK_AudioMute, spawn, {.v = volmute}},
    {0, XK_F1, spawn, {.v = volmute}},
    {0, XK_F2, spawn, {.v = volup}},
    {0, XK_F3, spawn, {.v = voldown}},
    {0, XK_F4, spawn, SHCMD("flameshot gui -p ~/documents/pictures/screenshots")},
    {0, XK_F7, spawn, {.v = brightdown}},
    {0, XK_F8, spawn, {.v = brightup}},
    {MODKEY, XK_e, spawn,
     SHCMD("source ~/.config/suckless/dwm/emojis-menu-picker/dmenu-emoji.sh")},
    {MODKEY, XK_b, spawn, {.v = brave}},
    {MODKEY, XK_p, spawn, {.v = dmenucmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_g, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | Mod1Mask, XK_h, incrgaps, {.i = +1}},
    {MODKEY | Mod1Mask, XK_l, incrgaps, {.i = -1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_h, incrogaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_l, incrogaps, {.i = -1}},
    {MODKEY | Mod1Mask | ControlMask, XK_h, incrigaps, {.i = +1}},
    {MODKEY | Mod1Mask | ControlMask, XK_l, incrigaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_0, togglegaps, {0}},
    {MODKEY | Mod1Mask | ShiftMask, XK_0, defaultgaps, {0}},
    {MODKEY, XK_y, incrihgaps, {.i = +1}},
    {MODKEY, XK_o, incrihgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_y, incrivgaps, {.i = +1}},
    {MODKEY | ControlMask, XK_o, incrivgaps, {.i = -1}},
    {MODKEY | Mod4Mask, XK_y, incrohgaps, {.i = +1}},
    {MODKEY | Mod4Mask, XK_o, incrohgaps, {.i = -1}},
    {MODKEY | ShiftMask, XK_y, incrovgaps, {.i = +1}},
    {MODKEY | ShiftMask, XK_o, incrovgaps, {.i = -1}},
    {MODKEY, XK_z, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_q, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button1, sigstatusbar, {.i = 1}},
    {ClkStatusText, 0, Button2, sigstatusbar, {.i = 2}},
    {ClkStatusText, 0, Button3, sigstatusbar, {.i = 3}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
