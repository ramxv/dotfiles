# Dotfiles

My personal configuration files for Linux, managed with GNU Stow.

## Structure

```
.
├── alacritty/     # Terminal emulator configuration
├── fastfetch/     # System info display tool
├── nvim/          # Neovim text editor
├── suckless/      # Suckless software (dwm, st, dmenu, dwmblocks)
├── tmux/          # Terminal multiplexer
└── zsh/           # Z shell configuration
```

## Contents

### alacritty
**Location:** `~/.config/alacritty/`

Terminal emulator configuration written in TOML format.
- `alacritty.toml` - Main configuration file (fonts, colors, keybindings)
- `themes/` - Color scheme definitions

**Configure:** Edit `alacritty/.config/alacritty/alacritty.toml`

### fastfetch
**Location:** `~/.config/fastfetch/`

System information tool configuration.
- `config.jsonc` - Display modules and formatting

**Configure:** Edit `fastfetch/.config/fastfetch/config.jsonc`

### nvim
**Location:** `~/.config/nvim/`

Neovim configuration using Lua and lazy.nvim plugin manager.
- `init.lua` - Main entry point
- `lua/` - Plugin configurations and settings
- `lazy-lock.json` - Plugin version lock file

**Configure:** Edit `nvim/.config/nvim/init.lua` and files in `nvim/.config/nvim/lua/`

### suckless
**Location:** `~/.config/suckless/`

Suckless software builds and configurations:
- `dwm/` - Dynamic window manager
- `st/` - Simple terminal
- `dmenu/` - Dynamic menu
- `dwmblocks/` - Status bar for dwm
- `patches/` - Custom patches

**Configure:** Edit the `config.h` files in each program's directory and recompile:
```bash
cd ~/.config/suckless/dwm
sudo make clean install
```

### tmux
**Location:** `~/`

Terminal multiplexer configuration.
- `.tmux.conf` - Main configuration file
- `.tmux/plugins/` - TPM (Tmux Plugin Manager) plugins

**Configure:** Edit `tmux/.tmux.conf`

### zsh
**Location:** `~/`

Z shell configuration.
- `.zshrc` - Shell configuration (aliases, functions, environment variables)

**Configure:** Edit `zsh/.zshrc`

## Installation

### Prerequisites
- [GNU Stow](https://www.gnu.org/software/stow/)
- Git

Install Stow:
```bash
# Arch Linux
sudo pacman -S stow

# Debian/Ubuntu
sudo apt install stow

# macOS
brew install stow
```

### Setup

1. Clone this repository:
```bash
git clone https://github.com/yourusername/dotfiles.git ~/github/dotfiles
cd ~/github/dotfiles
```

2. Stow the configurations you want:
```bash
# Install individual configurations
stow alacritty
stow nvim
stow tmux
stow zsh

# Or install everything at once
stow */
```

3. For suckless programs, compile and install:
```bash
cd ~/.config/suckless/dwm
sudo make clean install

cd ~/.config/suckless/st
sudo make clean install

cd ~/.config/suckless/dmenu
sudo make clean install

cd ~/.config/suckless/dwmblocks
sudo make clean install
```

### Unstowing

To remove a configuration:
```bash
stow -D alacritty
```

## How GNU Stow Works

Stow creates symlinks from this repository to your home directory. For example:
- `~/github/dotfiles/zsh/.zshrc` → `~/.zshrc`
- `~/github/dotfiles/nvim/.config/nvim/` → `~/.config/nvim/`

This allows you to manage all your dotfiles in one place while keeping them in their expected locations.

## Notes

- The `.stow-local-ignore` file prevents certain files (like this README) from being symlinked
- Always backup your existing configurations before stowing
- Some configurations may require additional dependencies to work properly

## License

Feel free to use and modify these configurations for your own setup.
