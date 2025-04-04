-- ~/.config/nvim/init.lua
require('packer').startup(function(use)
    use 'wbthomason/packer.nvim'
    use 'ful1e5/onedark.nvim'
    use 'neovim/nvim-lspconfig'
    use 'hrsh7th/nvim-cmp'
    use 'hrsh7th/cmp-nvim-lsp'
    use 'hrsh7th/cmp-buffer'
    use 'hrsh7th/cmp-path'
    use 'hrsh7th/cmp-cmdline'
    use 'L3MON4D3/LuaSnip'
    use 'nvim-tree/nvim-tree.lua'
    use 'Pocco81/auto-save.nvim'
    use 'morhetz/gruvbox'
    use 'romgrk/barbar.nvim'
    use 'nvim-tree/nvim-web-devicons'
end)

-- Общие настройки
vim.o.clipboard = 'unnamedplus' 
vim.cmd 'colorscheme onedark'
vim.o.number = true
vim.o.relativenumber = true
vim.o.tabstop = 4
vim.o.shiftwidth = 4
vim.o.expandtab = true 
vim.o.scrolloff = 10 

-- Auto-save
require("auto-save").setup {
    enabled = false,
    trigger_events = { "InsertLeave", "TextChanged" }
}

-- NvimTree
require('nvim-tree').setup({
    view = {
        width = 40,
    }
})

vim.api.nvim_set_keymap('n', '<C-e>', ':NvimTreeToggle<CR>', { noremap = true, silent = true })

-- Barbar.nvim (вкладки)
require('barbar').setup({  
    icons = {
        filetype = { enabled = false },
    },  
})  

-- Горячие клавиши для Barbar
vim.keymap.set('n', '<C-n>', ':BufferNext<CR>')
vim.keymap.set('n', '<C-p>', ':BufferPrevious<CR>')


-- LSP и автодополнение
local lspconfig = require('lspconfig')
local cmp = require('cmp')

cmp.setup({
    snippet = {
        expand = function(args)
            require('luasnip').lsp_expand(args.body)
        end,
    },
    mapping = {
        ['<C-n>'] = cmp.mapping.select_next_item(),
        ['<C-p>'] = cmp.mapping.select_prev_item(),
        ['<CR>'] = cmp.mapping.confirm({ select = true }),
    },
    sources = {
        { name = 'nvim_lsp' },
        { name = 'buffer' },
        { name = 'path' },
    },
})

-- Настройки LSP серверов
lspconfig.pyright.setup{}
lspconfig.clangd.setup{}
lspconfig.rust_analyzer.setup{}
