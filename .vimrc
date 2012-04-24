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
nmap <C-F11> :cclo<CR>
nmap <F7>  :cn<CR>
nmap <F6> :cp<CR>


map <F12> :!exctags  --extra=+q  --fields=+iaS --c++-kinds=+px -L cscope.files <CR>
"set taglist
"let Tlist_Auto_Open=1
let Tlist_Exit_OnlyWindow=1
let Tlist_Show_One_File=1
let Tlist_Ctags_Cmd="ctags"

"set cscope
if has("cscope")

    """"""""""""" Standard cscope/vim boilerplate

    " use both cscope and ctag for 'ctrl-]', ':ta', and 'vim -t'
    set cscopetag

    " check cscope for definition of a symbol before checking ctags: set to 1
    " if you want the reverse search order.
    set csto=0

    " add any cscope database in current directory
    if filereadable("cscope.out")
        cs add cscope.out  
    " else add the database pointed to by environment variable 
    elseif $CSCOPE_DB != ""
        cs add $CSCOPE_DB
    endif

    " show msg when any other cscope db added
    set cscopeverbose  
    set cscopequickfix=s-,c-,d-,i-,t-,e-


    """"""""""""" My cscope/vim key mappings
    "
    " The following maps all invoke one of the following cscope search types:
    "
    "   's'   symbol: find all references to the token under cursor
    "   'g'   global: find global definition(s) of the token under cursor
    "   'c'   calls:  find all calls to the function name under cursor
    "   't'   text:   find all instances of the text under cursor
    "   'e'   egrep:  egrep search for the word under cursor
    "   'f'   file:   open the filename under cursor
    "   'i'   includes: find files that include the filename under cursor
    "   'd'   called: find functions that function under cursor calls
    "
    " Below are three sets of the maps: one set that just jumps to your
    " search result, one that splits the existing vim window horizontally and
    " diplays your search result in the new window, and one that does the same
    " thing, but does a vertical split instead (vim 6 only).
    "
    " I've used CTRL-\ and CTRL-@ as the starting keys for these maps, as it's
    " unlikely that you need their default mappings (CTRL-\'s default use is
    " as part of CTRL-\ CTRL-N typemap, which basically just does the same
    " thing as hitting 'escape': CTRL-@ doesn't seem to have any default use).
    " If you don't like using 'CTRL-@' or CTRL-\, , you can change some or all
    " of these maps to use other keys.  One likely candidate is 'CTRL-_'
    " (which also maps to CTRL-/, which is easier to type).  By default it is
    " used to switch between Hebrew and English keyboard mode.
    "
    " All of the maps involving the <cfile> macro use '^<cfile>$': this is so
    " that searches over '#include <time.h>" return only references to
    " 'time.h', and not 'sys/time.h', etc. (by default cscope will return all
    " files that contain 'time.h' as part of their name).


    " To do the first type of search, hit 'CTRL-\', followed by one of the
    " cscope search types above (s,g,c,t,e,f,i,d).  The result of your cscope
    " search will be displayed in the current window.  You can use CTRL-T to
    " go back to where you were before the search.  
    "

    nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>	
    nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
    nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>	


    " Using 'CTRL-spacebar' (intepreted as CTRL-@ by vim) then a search type
    " makes the vim window split horizontally, with search result displayed in
    " the new window.
    "
    " (Note: earlier versions of vim may not have the :scs command, but it
    " can be simulated roughly via:
    "    nmap <C-/>s <C-W><C-S> :cs find s <C-R>=expand("<cword>")<CR><CR>	

    nmap <C-/>s :scs find s <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-/>g :scs find g <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-/>c :scs find c <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-/>t :scs find t <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-/>e :scs find e <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-/>f :scs find f <C-R>=expand("<cfile>")<CR><CR>	
    nmap <C-/>i :scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>	
    nmap <C-/>d :scs find d <C-R>=expand("<cword>")<CR><CR>	


    " Hitting CTRL-space *twice* before the search type does a vertical 
    " split instead of a horizontal one (vim 6 and up only)
    "
    " (Note: you may wish to put a 'set splitright' in your .vimrc
    " if you prefer the new window on the right instead of the left

    nmap <C-/><C-/>s :vert scs find s <C-R>=expand("<cword>")<CR><CR>
    nmap <C-/><C-/>g :vert scs find g <C-R>=expand("<cword>")<CR><CR>
    nmap <C-/><C-/>c :vert scs find c <C-R>=expand("<cword>")<CR><CR>
    nmap <C-/><C-/>t :vert scs find t <C-R>=expand("<cword>")<CR><CR>
    nmap <C-/><C-/>e :vert scs find e <C-R>=expand("<cword>")<CR><CR>
    nmap <C-/><C-/>f :vert scs find f <C-R>=expand("<cfile>")<CR><CR>	
    nmap <C-/><C-/>i :vert scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>	
    nmap <C-/><C-/>d :vert scs find d <C-R>=expand("<cword>")<CR><CR>


    """"""""""""" key map timeouts
    "
    " By default Vim will only wait 1 second for each keystroke in a mapping.
    " You may find that too short with the above typemaps.  If so, you should
    " either turn off mapping timeouts via 'notimeout'.
    "
    "set notimeout 
    "
    " Or, you can keep timeouts, by uncommenting the timeoutlen line below,
    " with your own personal favorite value (in milliseconds):
    "
    "set timeoutlen=4000
    "
    " Either way, since mapping timeout settings by default also set the
    " timeouts for multicharacter 'keys codes' (like <F1>), you should also
    " set ttimeout and ttimeoutlen: otherwise, you will experience strange
    " delays as vim waits for a keystroke after you hit ESC (it will be
    " waiting to see if the ESC is actually part of a key code like <F1>).
    "
    "set ttimeout 
    "
    " personally, I find a tenth of a second to work well for key code
    " timeouts. If you experience problems and have a slow terminal or network
    " connection, set it higher.  If you don't set ttimeoutlen, the value for
    " timeoutlent (default: 1000 = 1 second, which is sluggish) is used.
    "
    "set ttimeoutlen=100

endif

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
nmap <F8> :WMToggle<cr>

""""""""""""""""""""""""""""""
" lookupfile setting
""""""""""""""""""""""""""""""
let g:LookupFile_MinPatLength = 3               "×îÉÙÊäÈë2¸ö×Ö·û²Å¿ªÊ¼²éÕÒ
let g:LookupFile_PreserveLastPattern = 0        "²»±£´æÉÏ´Î²éÕÒµÄ×Ö·û´®
let g:LookupFile_PreservePatternHistory = 1     "±£´æ²éÕÒÀúÊ·
let g:LookupFile_AlwaysAcceptFirst = 1          "»Ø³µ´ò¿ªµÚÒ»¸öÆ¥ÅäÏîÄ¿
let g:LookupFile_AllowNewFiles = 0              "²»ÔÊÐí´´½¨²»´æÔÚµÄÎÄ¼þ
if filereadable("./filenametags")                "ÉèÖÃtagÎÄ¼þµÄÃû×Ö
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

"ÐÐºÅ
set nu

"¹â±êÏß
set cursorline

"¹¤×÷ÔÚ²»¼æÈÝÄ£Ê½ÏÂ
set nocp

"´ò¿ªVIM×´Ì¬À¸±ê³ß
set ru

"ËÑË÷Ê±¸ßÁÁÏÔÊ¾±»ÕÒµ½µÄÎÄ±¾
set hls

"ËÑË÷Ê±ÔÚÎ´ÍêÈ«ÊäÈëÍê±ÏÒª¼ìË÷µÄÎÄ±¾Ê±¾Í¿ªÊ¼¼ìË÷
set is

"´ò¿ª¹Ø¼ü×Ö¸ßÁÁ
syntax on

"BackspaceÉ¾³ý
set backspace=indent,eol,start
"set backspace=2

"×óÓÒµ½Í·Ê±×Ô¶¯ÇÐ»»µ½ÉÏÏÂÐÐ
set whichwrap=b,s,<,>,[,] 

"ÄÚÂëÊ¹ÓÃutf8£¬ÓÅÏÈÒÔutf8³¢ÊÔ½âÂë
set encoding=utf8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936

"×Ô¶¯Ëõ½ø4¸ö¿Õ¸ñ
set sw=4

"Tab¿í¶È4¸ö×Ö·û
set ts=4

"²»ÔÚµ¥´ÊÖÐ¼ä¶ÏÐÐ
set lbr

"´ò¿ª¶ÏÐÐÄ£Ê½¶ÔÑÇÖÞÓïÑÔÖ§³Ö
set fo+=mB 

"ÏÔÊ¾À¨ºÅÅä¶ÔÇé¿ö
set sm

"´ò¿ªC/C++·ç¸ñµÄ×Ô¶¯Ëõ½ø
set cin

"ÊÇ·ñÔÚËõ½øºÍÓöµ½ Tab ¼üÊ±Ê¹ÓÃ¿Õ¸ñÌæ´ú£»Ê¹ÓÃ noexpandtab È¡ÏûÉèÖÃ
set expandtab

"×Ô¶¯Ëõ½ø£¬¼´Ã¿ÐÐµÄËõ½øÖµÓëÉÏÒ»ÐÐÏàµÈ£»Ê¹ÓÃ noautoindent È¡ÏûÉèÖÃ
set autoindent

"°´BackSpaceµÄÊ±ºò¿ÉÒÔÒ»´ÎÉ¾³ý4¸ö¿Õ¸ñ
set softtabstop=4

"¼ì²âÎÄ¼þÀàÐÍ
"filetype on

"¼ì²âÎÄ¼þÀàÐÍ²å¼þ
"filetype plugin on

"ÉÏÏÂ¿ÉÊÓÐÐÊý
set scrolloff=6

"ÔÚÐÐºÍ¶Î¿ªÊ¼´¦Ê¹ÓÃÖÆ±í·û
set smarttab

"ÔöÇ¿Ä£Ê½ÖÐµÄÃüÁîÐÐ×Ô¶¯Íê³É²Ù×÷
set wildmenu

"´ò¿ª×Ô¶¯ÕÛµþ
"set foldenable
"set foldmethod=indent

"Ã¿Ò»ÐÐÁÐÊý£¬ÓÃÓÚ×Ô¶¯»»ÐÐ
"set textwidth=78

"set columns=85

"ÐÐºÅ¿í¶È
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
let Tlist_Auto_Open = 0
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
set tags+=~/.vim/tags/linux-kernel.tags

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
set foldlevel=1000
highlight Pmenu ctermbg=darkred
highlight PmenuSel ctermbg=red ctermfg=yellow
"au BufRead,BufNewFile *.c,*.cpp,*.py match Error /\%80v.\%81v./
au BufRead,BufNewFile *.c,*.cpp,*.py 2match Underlined /.\%81v/
"set colorcolumn=81
