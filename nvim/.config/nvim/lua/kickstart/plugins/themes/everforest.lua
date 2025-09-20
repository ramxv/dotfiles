return {
  'neanias/everforest-nvim',
  name = 'everforest',
  config = function()
    require('everforest').setup {
      version = false,
      lazy = false,
      priority = 1000,
      background = 'hard',
      transparent_background_level = 1,
      italics = true,
      disable_italic_comments = false,
      inlay_hints_background = 'dimmed',
    }
    vim.cmd 'colorscheme everforest'
  end,
}
