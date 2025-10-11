// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
#define DATEDWMBLOCK "/home/thanatos/.config/suckless/dwmblocks/scripts/date"
#define TIMEDWMBLOCK "/home/thanatos/.config/suckless/dwmblocks/scripts/time"
#define BATTERYDWMBLOCK                                                        \
  "/home/thanatos/.config/suckless/dwmblocks/scripts/battery"
#define WIFIDWMBLOCK "/home/thanatos/.config/suckless/dwmblocks/scripts/wifi"
#define VOLDWMBLOCK "/home/thanatos/.config/suckless/dwmblocks/scripts/volume"
#define KBLAYWMBLOCK                                                           \
  "/home/thanatos/.config/suckless/dwmblocks/scripts/kblayout"
#define POWERDWMBLOCK "/home/thanatos/.config/suckless/dwmblocks/scripts/power"

static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/

    {"    ", DATEDWMBLOCK, 3600, 1},

    {"󱑍  ", TIMEDWMBLOCK, 5, 0},

    {"   ", KBLAYWMBLOCK, 0, 3},

    {"󰍛  ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g", 30, 0},

    {"󰂄 ", BATTERYDWMBLOCK, 30, 0},

    {"", VOLDWMBLOCK, 0, 10},

    {"󰖩  ", WIFIDWMBLOCK, 1000, 0},

    {"", POWERDWMBLOCK, 0, 9},
};

// sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 15;
