set nocompatible
set fileencodings=gb2312,gbk
set nomodeline
"set gui font
set guifont=WenQuanYi\ Micro\ Hei\ Mono\ 11
"set mouse=a
"set number
set helplang=cn
syntax on
set nobackup
set ignorecase
set ttymouse=xterm2
set ruler
set wrap
set incsearch
set showcmd
set showmode
set cindent
set autoindent
set showmatch
set smartindent
set writebackup


filetype plugin indent on

colorscheme delek

set backspace=indent,eol,start
set hlsearch
"set tab quick access
nmap <F11> :cope<CR>

"set folding
"set foldmethod=syntax

"set tabwidth
set sw=4
set ts=4
"set smarttab
set softtabstop=4
set noet

"set winmanager
let g:winManagerWindowLayout = "FileExplorer|TagList"
let g:winManagerWidth = 30
let g:defaultExplorer = 0

nmap <C-W><C-F> :FirstExplorerWindow<cr>
nmap <C-W><C-B> :BottomExplorerWindow<cr>
nmap <C-W><C-T> :WMToggle<cr>
nmap <F1> :WMToggle<cr>

""""""""""""""""""""""""""""""
" lookupfile setting
""""""""""""""""""""""""""""""
nmap <C-F> :LookupFile<cr>
let g:LookupFile_MinPatLength = 3               "×îÉÙÊäÈë2¸ö×Ö·û²Å¿ªÊ¼²éÕÒ
let g:LookupFile_PreserveLastPattern = 0        "²»±£´æÉÏ´Î²éÕÒµÄ×Ö·û´®
let g:LookupFile_PreservePatternHistory = 1     "±£´æ²éÕÒÀúÊ·
let g:LookupFile_AlwaysAcceptFirst = 1          "»Ø³µ´ò¿ªµÚÒ»¸öÆ¥ÅäÏîÄ¿
let g:LookupFile_AllowNewFiles = 0              "²»ÔÊĞí´´½¨²»´æÔÚµÄÎÄ¼ş
if filereadable("./filenametags")                "ÉèÖÃtagÎÄ¼şµÄÃû×Ö
    let g:LookupFile_TagExpr = '"./filenametags"'
endif             "
"""""""""""""""""""""""""""""""""""
" OmniCpp
"""""""""""""""""""""""""""""""""""

let OmniCpp_DefaultNampspaces=["std"]
let OmniCpp_MayCompleteScope=1
set completeopt=longest,menu

set nomodeline

"let g:EchoFuncKeyPrev='<C-b>'
"let g:EchoFuncKeyNext='<C-n>'

"ĞĞºÅ
set nu

"¹â±êÏß
set cursorline

"¹¤×÷ÔÚ²»¼æÈİÄ£Ê½ÏÂ
set nocp

"´ò¿ªVIM×´Ì¬À¸±ê³ß
set ru

"ËÑË÷Ê±¸ßÁÁÏÔÊ¾±»ÕÒµ½µÄÎÄ±¾
set hls

"ËÑË÷Ê±ÔÚÎ´ÍêÈ«ÊäÈëÍê±ÏÒª¼ìË÷µÄÎÄ±¾Ê±¾Í¿ªÊ¼¼ìË÷
set is

"´ò¿ª¹Ø¼ü×Ö¸ßÁÁ
syntax on

"BackspaceÉ¾³ı
set backspace=indent,eol,start
"set backspace=2

"×óÓÒµ½Í·Ê±×Ô¶¯ÇĞ»»µ½ÉÏÏÂĞĞ
set whichwrap=b,s,<,>,[,] 

"ÄÚÂëÊ¹ÓÃutf8£¬ÓÅÏÈÒÔutf8³¢ÊÔ½âÂë
set encoding=utf8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936

"×Ô¶¯Ëõ½ø4¸ö¿Õ¸ñ
set sw=4

"Tab¿í¶È4¸ö×Ö·û
set ts=4

"²»ÔÚµ¥´ÊÖĞ¼ä¶ÏĞĞ
set lbr

"´ò¿ª¶ÏĞĞÄ£Ê½¶ÔÑÇÖŞÓïÑÔÖ§³Ö
set fo+=mB 

"ÏÔÊ¾À¨ºÅÅä¶ÔÇé¿ö
set sm

"´ò¿ªC/C++·ç¸ñµÄ×Ô¶¯Ëõ½ø
set cin

"ÊÇ·ñÔÚËõ½øºÍÓöµ½ Tab ¼üÊ±Ê¹ÓÃ¿Õ¸ñÌæ´ú£»Ê¹ÓÃ noexpandtab È¡ÏûÉèÖÃ
set expandtab

"×Ô¶¯Ëõ½ø£¬¼´Ã¿ĞĞµÄËõ½øÖµÓëÉÏÒ»ĞĞÏàµÈ£»Ê¹ÓÃ noautoindent È¡ÏûÉèÖÃ
set autoindent

"°´BackSpaceµÄÊ±ºò¿ÉÒÔÒ»´ÎÉ¾³ı4¸ö¿Õ¸ñ
set softtabstop=4

"¼ì²âÎÄ¼şÀàĞÍ
"filetype on

"¼ì²âÎÄ¼şÀàĞÍ²å¼ş
"filetype plugin on

"ÉÏÏÂ¿ÉÊÓĞĞÊı
set scrolloff=6

"ÔÚĞĞºÍ¶Î¿ªÊ¼´¦Ê¹ÓÃÖÆ±í·û
set smarttab

"ÔöÇ¿Ä£Ê½ÖĞµÄÃüÁîĞĞ×Ô¶¯Íê³É²Ù×÷
set wildmenu

"´ò¿ª×Ô¶¯ÕÛµş
"set foldenable
"set foldmethod=indent

"Ã¿Ò»ĞĞÁĞÊı£¬ÓÃÓÚ×Ô¶¯»»ĞĞ
"set textwidth=78

"set columns=85

"ĞĞºÅ¿í¶È
set numberwidth=5

if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

let mapleader=","

" An example for a vimrc file.
"
" Maintainer:	Bram Moolenaar <Bram@vim.org>
" Last change:	2006 Nov 16
"
" To use it, copy it to
"     for Unix and OS/2:  ~/.vimrc
"	      for Amiga:  s:.vimrc
"  for MS-DOS and Win32:  $VIM\_vimrc
"	    for OpenVMS:  sys$login:.vimrc
"
if has("terminfo")
   set t_Co=8
   set t_Sf=[3%p1%dm
   set t_Sb=[4%p1%dm
else
   set t_Co=8
   set t_Sf=[3%dm
   set t_Sb=[4%dm
endif

" When started as "evim", evim.vim will already have done these settings.
if v:progname =~? "evim"
  finish
endif

" Use Vim settings, rather then Vi settings (much better!).
" This must be first, because it changes other options as a side effect.
set nocompatible

" allow backspacing over everything in insert mode
set backspace=indent,eol,start

if has("vms")
  set nobackup		" do not keep a backup file, use versions instead
else
  set backup		" keep a backup file
endif
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time
set showcmd		" display incomplete commands
set incsearch		" do incremental searching

" For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" Don't use Ex mode, use Q for formatting
map Q gq

" In many terminal emulators the mouse works just fine, thus enable it.
set mouse=a

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  set hlsearch
endif

" Only do this part when compiled with support for autocommands.
if has("autocmd")

  " Enable file type detection.
  " Use the default filetype settings, so that mail gets 'tw' set to 72,
  " 'cindent' is on in C files, etc.
  " Also load indent files, to automatically do language-dependent indenting.
  filetype plugin indent on

  " Put these in an autocmd group, so that we can delete them easily.
  augroup vimrcEx
  au!

  " For all text files set 'textwidth' to 78 characters.
  autocmd FileType text setlocal textwidth=78

  " When editing a file, always jump to the last known cursor position.
  " Don't do it when the position is invalid or when inside an event handler
  " (happens when dropping a file on gvim).
  autocmd BufReadPost *
    \ if line("'\"") > 0 && line("'\"") <= line("$") |
    \   exe "normal! g`\"" |
    \ endif

  augroup END

else

  set autoindent		" always set autoindenting on

endif " has("autocmd")

" Convenient command to see the difference between the current buffer and the
" file it was loaded from, thus the changes you made.
command DiffOrig vert new | set bt=nofile | r # | 0d_ | diffthis
	 	\ | wincmd p | diffthis

" Taglist
"let Tlist_Auto_Open = 1
let Tlist_Show_One = 1
let Tlist_Exit_OnlyWindow = 1
let Tlist_Ctags_Cmd="ctags"
let Tlist_Sort_Type="name"
set tags=tags
set tags+=./tags
set tags+=~/.vim/tags/libc.tags
set tags+=~/.vim/tags/susv2.tags
set tags+=~/.vim/tags/glib.tags
set tags+=~/.vim/tags/cpp.tags

set completeopt=longest,menu

" cscope
if has("cscope")
	set cscopequickfix=s-,c-,d-,i-,t-,e-
endif

" OmniCppComplete
let OmniCpp_NamespaceSearch = 1
let OmniCpp_GlobalScopeSearch = 1
let OmniCpp_ShowAccess = 1
let OmniCpp_MayCompleteDot = 1
let OmniCpp_MayCompleteArrow = 1
let OmniCpp_MayCompleteScope = 1
let OmniCpp_DefaultNamespaces = ["std", "_GLIBCXX_STD"]

" SuperTab
let g:SuperTabRetainCompletionType=2
let g:SuperTabDefaultCompletionType="<C-X><C-O>"

" Favourate
set tabstop=4
set shiftwidth=4
set number
set nobackup
colorscheme default

" Chinese help
if  version >= 603
	set helplang=cn
endif

set mouse=c

"autocmd BufNewFile *.html 0r ~/.vim/skel/dot.html
"autocmd BufNewFile *.h    0r ~/.vim/skel/dot.h   | exe "%s/<FILE>/".expand("%")
"autocmd BufNewFile *.c    0r ~/.vim/skel/dot.c   | exe "%s/<FILE>/".expand("%")
"autocmd BufNewFile *.cpp  0r ~/.vim/skel/dot.cpp | exe "%s/<FILE>/".expand("%")
"autocmd BufNewFile *.pc   0r ~/.vim/skel/dot.pc  | exe "%s/<FILE>/".expand("%")
"autocmd BufNewFile *.ec   0r ~/.vim/skel/dot.ec  | exe "%s/<FILE>/".expand("%")

set cindent

" Doxygen
let g:load_doxygen_syntax=1

" Fold
set foldmethod=indent
set foldlevel=10
