import zx

#
# entrance rooms
#
zx.map_load_room(entrance=True, room_data=[
"      ^      ","             ","             ","             ","             ",
"   .r....... ","             ","             ","             ","      ^      ",
"  r.r....... ","      ^      ","             ","      ^      ","  .  ...     ",
" .r.r....... ","    .....    ","    .....    ","    m....    "," .........   ",
" .r......... ","    .www.    ","    .w.w.    ","    .w.w.    ","...........  ",
"<...........>","   <..S..>   ","   <..S..>   ","   <..S..    ","............ ",
" ........... ","    .w...    ","    .wmw.    ","    .w...    ","............ ",
" ..S.....m.. ","    ...m.    ","    .....    ","    ....m    ","......k....  ",
"..rrrrrrrr.. ","             ","             ","             ","......xxx..  ",
"...rrrrr.... ","             ","             ","             ","..S......... ",
"...........  ","             ","             ","             ",".xxxxxx....  ",
"..........   ","             ","             ","             "," .....x.m... ",
"  ....v...   ","             ","             ","             ","    ..xxxx   ",
])

#
# exit rooms
#
zx.map_load_room(exit=True, room_data=[
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"      ^      ","      ^      ","             ","      ^      ","      ^      ",
"    ww...    ","    .....    ","    .....    ","    .....    ","    .....    ",
"    ww...    ","    .w...    ","    .w...    ","    .w...    ","    .w...    ",
"   <..E..>   ","   <..E..>   ","   <..E..>   ","   <..E..    ","    ..E..    ",
"    .www.    ","    .w...    ","    .w...    ","    .w...    ","    .w...    ",
"    ...ww    ","    .....    ","    .....    ","    .....    ","    .....    ",
"      v      ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

#
# directional combined with exit rooms
#
zx.map_load_room(left=True, room_data=[
"             ","             ","             ","             ","             ",
"      ^      ","      ^      ","             ","      ^      ","      ^      ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"  ....w....  ","  ....w....  ","  ....w....  ","  ....w....  ","  ....w....  ",
"  ...ww....  ","  ...ww....  ","  ...ww....  ","  ...ww....  ","  ...ww....  ",
" <..wwwww..> "," <..wwwww..> "," <..wwwww..> "," <..wwwww..  ","  ..wwwww..  ",
"  ...ww....  ","  ...ww....  ","  ...ww....  ","  ...ww....  ","  ...ww....  ",
"  ....w....  ","  ....w....  ","  ....w....  ","  ....w....  ","  ....w....  ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"      v      ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

#
# lock rooms
#
zx.map_load_room(lock=True, room_data=[
"    ^X  X    ","             ","             ","             ","             ",
"  X .....    ","      ^      ","             ","      ^      ","      ^      ",
"  ....|....X ","  .........  ","  .........  ","  .........  ","  .........  ",
"<...|.w.|..  ","  .........  ","  .........  ","  .........  ","  .........  ",
"  ...www.... ","  ...w.....  ","  ...w.....  ","  ...w.....  ","  ...w.....  ",
"  .|wwfww|..>"," <...w.....> "," <...w.....> "," <...w.....  ","  ...w.....  ",
" X...www.... ","  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ",
"  ..|.w.|..X ","  .........  ","  .........  ","  .........  ","  .........  ",
"   ...|...   ","  .........  ","  .........  ","  .........  ","  .........  ",
"   X ... X   ","             ","             ","             ","             ",
"      v      ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

#
# key rooms
#
zx.map_load_room(key=True, room_data=[
"             ","             ","             ","             ","             ",
"    ^        ","    ^        ","             ","    ^        ","    ^        ",
"  .........  ","  .........  ","  .........  ","  .........  ","  ........k  ",
"  .........  ","  .........  ","  ...k.....  ","  .......k.  ","  .........  ",
"  .....k...  ","  .........  ","  .........  ","  .........  ","  .........  ",
" <.........  "," <.........  "," <.........  "," <.........  ","  .........  ",
"  .........> ","  ....k....> ","  .........> ","  .........  ","  .........  ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"        v    ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

#
# depth 1 rooms
#
zx.map_load_room(depth=1, room_data=[
"             ","             ","             ","             ","             ",
"    ^        ","    ^        ","             ","    ^        ","    ^        ",
"  .........  ","  ww.......  ","  .........  ","  .........  ","  .........  ",
"  ...ww....  ","  www......  ","  ...ww....  ","  ...ww....  ","  ...ww....  ",
"  ....w....  ","  .w.w.....  ","  ....w....  ","  ....w....  ","  ....w....  ",
" <....w....  "," <...www...  "," <....w....  "," <....w....  ","  ....w....  ",
"  ....w....> ","  ....www..> ","  ....w....> ","  ....w....  ","  ....w....  ",
"  ...www...  ","  .........  ","  ...www...  ","  ...www...  ","  ...www...  ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"        v    ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

#
# depth 2 rooms
#
zx.map_load_room(depth=2, room_data=[
"             ","             ","             ","             ","             ",
"    ^        ","    ^        ","             ","    ^        ","    ^        ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"  ...ww....  ","  ...ww....  ","  ...ww....  ","  ...ww....  ","  ...ww....  ",
"  .....w...  ","  .....w...  ","  .....w...  ","  .....w...  ","  .....w...  ",
" <...www...  "," <...www...  "," <...www...  "," <...www...  ","  ...www...  ",
"  ...w.....> ","  ...w.....> ","  ...w.....> ","  ...w.....  ","  ...w.....  ",
"  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"        v    ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

#
# depth 3 rooms
#
zx.map_load_room(depth=3, room_data=[
"             ","             ","             ","             ","             ",
"    ^        ","    ^        ","             ","    ^        ","    ^        ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ",
"  .....w...  ","  .....w...  ","  .....w...  ","  .....w...  ","  .....w...  ",
" <...www...  "," <...www...  "," <...www...  "," <...www...  ","  ...www...  ",
"  .....w...> ","  .....w...> ","  .....w...> ","  .....w...  ","  .....w...  ",
"  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"        v    ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

#
# depth 4 rooms
#
zx.map_load_room(depth=4, room_data=[
"             ","             ","             ","             ","             ",
"    ^        ","    ^        ","             ","    ^        ","    ^        ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"  ...w.w...  ","  ...w.w...  ","  ...w.w...  ","  ...w.w...  ","  ...w.w...  ",
"  ...w.w...  ","  ...w.w...  ","  ...w.w...  ","  ...w.w...  ","  ...w.w...  ",
" <...www...  "," <...www...  "," <...www...  "," <...www...  ","  ...www...  ",
"  .....w...> ","  .....w...> ","  .....w...> ","  .....w...  ","  .....w...  ",
"  .....w...  ","  .....w...  ","  .....w...  ","  .....w...  ","  .....w...  ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"        v    ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

#
# depth 5 rooms
#
zx.map_load_room(depth=5, room_data=[
"             ","             ","             ","             ","             ",
"    ^        ","    ^        ","             ","    ^        ","    ^        ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ",
"  ...w.....  ","  ...w.....  ","  ...w.....  ","  ...w.....  ","  ...w.....  ",
" <...wfw...  "," <...wfw.f.  "," <...wfw...  "," <.f.www...  ","  .f.wfw...  ",
"  .....w...> ","  .....w...> ","  .....w...> ","  .....w...  ","  .....w...  ",
"  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"        v    ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

#
# depth 6 rooms
#
zx.map_load_room(depth=6, room_data=[
"             ","             ","             ","             ","             ",
"    ^        ","    ^        ","             ","    ^        ","    ^        ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ",
"  ...w.....  ","  ...w.....  ","  ...w.....  ","  ...w.....  ","  ...w.....  ",
" <...www...  "," <...www...  "," <...www...  "," <...www...  ","  ...www...  ",
"  ...www...> ","  ...www...> ","  ...www...> ","  ...www...  ","  ...www...  ",
"  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ","  ...www...  ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"        v    ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

#
# secret rooms
#
zx.map_load_room(secret=True, room_data=[
"             ","             ","             ","             ","             ",
"    ^        ","    ^        ","             ","    ^        ","    ^        ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"  ...ww....  ","  ...ww....  ","  ...ww....  ","  ...ww....  ","  ...ww....  ",
"  ..w..w...  ","  ..w..w...  ","  ..w..w...  ","  ..w..w...  ","  ..w..w...  ",
" <....w....  "," <....w....  "," <....w....  "," <....w....  ","  ....w....  ",
"  ....w....> ","  ....w....> ","  ....w....> ","  ....w....  ","  ....w....  ",
"  ....w....  ","  ....w....  ","  ....w....  ","  ....w....  ","  ....w....  ",
"  .........  ","  .........  ","  .........  ","  .........  ","  .........  ",
"        v    ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
"             ","             ","             ","             ","             ",
])

