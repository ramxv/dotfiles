-- lua/plugins/rose-pine.lua
return {
  'rose-pine/neovim',
  name = 'rose-pine',
  config = function()
    require('rose-pine').setup {
      variant = 'main', -- auto, main, moon, or dawn
      dark_variant = 'main', -- main, moon, or dawn
      dim_inactive_windows = false,
      extend_background_behind_borders = true,

      styles = {
        bold = false,
        italic = false,
        transparency = true,
      },
    }
    -- vim.cmd 'colorscheme rose-pine'
  end,
}
