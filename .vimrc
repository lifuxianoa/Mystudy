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
let g:LookupFile_MinPatLength = 3               "最少输入2个字符才开始查找
let g:LookupFile_PreserveLastPattern = 0        "不保存上次查找的字符串
let g:LookupFile_PreservePatternHistory = 1     "保存查找历史
let g:LookupFile_AlwaysAcceptFirst = 1          "回车打开第一个匹配项目
let g:LookupFile_AllowNewFiles = 0              "不允许创建不存在的文件
if filereadable("./filenametags")                "设置tag文件的名字
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

"行号
set nu

"光标线
set cursorline

"工作在不兼容模式下
set nocp

"打开VIM状态栏标尺
set ru

"搜索时高亮显示被找到的文本
set hls

"搜索时在未完全输入完毕要检索的文本时就开始检索
set is

"打开关键字高亮
syntax on

"Backspace删除
set backspace=indent,eol,start
"set backspace=2

"左右到头时自动切换到上下行
set whichwrap=b,s,<,>,[,] 

"内码使用utf8，优先以utf8尝试解码
set encoding=utf8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936

"自动缩进4个空格
set sw=4

"Tab宽度4个字符
set ts=4

"不在单词中间断行
set lbr

"打开断行模式对亚洲语言支持
set fo+=mB 

"显示括号配对情况
set sm

"打开C/C++风格的自动缩进
set cin

"是否在缩进和遇到 Tab 键时使用空格替代；使用 noexpandtab 取消设置
set expandtab

"自动缩进，即每行的缩进值与上一行相等；使用 noautoindent 取消设置
set autoindent

"按BackSpace的时候可以一次删除4个空格
set softtabstop=4

"检测文件类型
"filetype on

"检测文件类型插件
"filetype plugin on

"上下可视行数
set scrolloff=6

"在行和段开始处使用制表符
set smarttab

"增强模式中的命令行自动完成操作
set wildmenu

"打开自动折叠
"set foldenable
"set foldmethod=indent

"每一行列数，用于自动换行
"set textwidth=78

"set columns=85

"行号宽度
set numberwidth=5

if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

let mapleader=","
