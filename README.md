# Smallwat3r's QMK Keymap

Custom 26-key layout for the [Smallcat](https://github.com/smallwat3r/smallcat) keyboard, designed to minimize pinky strain.

Uses very light switches (Kailh Ambients Nocturnal, 20g) and relies heavily on combos for missing keys.

## Building

```
make             # Show available targets
make all         # Build all keyboards
make 26          # Build smallcat/26
make uni         # Build smallcat/uni
make flash-26    # Flash smallcat/26
make flash-uni   # Flash smallcat/uni
make format      # Format code with clang-format
make autocorrect # Generate autocorrect data from dictionary
make clean       # Clean build artifacts
```

Compiled UF2 files are placed in the `uf2/` directory.

## Smallcat keymap

Legend: `░░░░` = held key to activate layer

```
BASE
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │ L  │ D  │ P  │                    │ F  │ O  │ U  │
┌────┼────┼────┼UNI─┼────┐          ┌────┼────┼────┼────┼────┐
│ W  │ R  │ T  │ S  │ G  │          │ Y  │ N  │ A  │ E  │ I  │
└LSft┼SYM2┼NUM─┼NAV─┼ROS─┘          └────┼SYS─┼────┼SYM2┼RSft┘
     │ K  │ M  │ C  │                    │ H  │ ,  │ .  │
     └LCtl┴LAlt┴LGui┘                    └RGui┴RAlt┴RCtl┘
               ┌────┬────┐    ┌────┬────┐
               │Tab │Spc │    │Bsp │Ent │
               └EDIT┴FUN─┘    └SYS─┴SYM─┘

  Combos (left):
    L+D+P = Z     D+P = Q     L+P = [      K+C = (
    R+T = B       R+C = "br"  K+M = X      M+C = J      T+C = V
    T+S = "th"    W+S = "wh"
    R+S tap = "sh"      R+S hold = Ctl+Gui
    R+T+S tap = OSM Sft R+T+S hold = Sft+Ctl+Gui
    W+C = ".com"              W+G = "smallwat3r"

  Combos (right):
    N+A+E = Esc  N+E = '      F+U = ]      H+. = )
    H+A = _      H+, = -      ,+. = ;
    U+N = "you"  H+E = "ion"  N+I = "ing"

  Combos (both):
    S+N = Caps Word           G+Y = Screenshot

NUM (hold T) - number pad
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │    │    │    │                    │ 7  │ 8  │ 9  │
┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
│    │    │░░T░│ .  │    │          │000 │ 4  │ 5  │ 6  │ 0  │
└────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
     │    │    │ ,  │                    │ 1  │ 2  │ 3  │
     └────┴────┴────┘                    └────┴────┴────┘
               ┌────┬────┐    ┌────┬────┐
               │    │Spc │    │Bsp │Del │
               └────┴────┘    └────┴────┘

SYM (hold Ent) - symbols
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │ @  │ £  │ $  │                    │ \  │ /  │ ?  │
┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
│ *  │ -  │ =  │ "  │ %  │          │ !  │ :  │ #  │ ~  │ |  │
└────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
     │ +  │ &  │ `  │                    │ <  │ >  │ -> │
     └────┴────┴────┘                    └────┴────┴────┘
               ┌────┬────┐    ┌────┬────┐
               │    │Spc │    │    │░░░░│
               └────┴────┘    └────┴────┘

  Combos: £+$ = €    =+" = \"\"\"    &+` = ```    *+Spc = indent

SYM2 (hold R or E) - symbols with home row passthrough for rolls
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │ @  │ £  │ $  │                    │ \  │ /  │ ?  │
┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
│ *  │░░R░│ =  │ "  │ %  │          │ !  │ :  │ a  │░░E░│ |  │
└────┼─r──┼────┼────┼────┘          └────┼────┼────┼─e──┼────┘
     │ +  │ &  │ `  │                    │ <  │ >  │ -> │
     └────┴────┴────┘                    └────┴────┴────┘
               ┌────┬────┐    ┌────┬────┐
               │    │Spc │    │    │    │
               └────┴────┘    └────┴────┘

  Combos: £+$ = €    =+" = \"\"\"    &+` = ```    *+Spc = indent

NAV (hold S) - navigation and brackets
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │    │    │    │                    │ {  │ }  │    │
┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
│End │    │NAV2│░░S░│    │          │ ←  │ ↓  │ ↑  │ →  │Home│
└────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
     │    │    │    │                    │ [  │ ]  │    │
     └────┴────┴────┘                    └────┴────┴────┘
               ┌────┬────┐    ┌────┬────┐
               │ M2 │ M1 │    │Bsp │Del │
               └────┴────┘    └────┴────┘

NAV2 (hold S + NAV2) - word navigation and selection
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │    │    │    │                    │    │    │    │
┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
│    │    │░░░░│░░S░│    │          │ ←W │SelB│SelF│ →W │    │
└────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
     │    │    │    │                    │Sel │    │    │
     └────┴────┴────┘                    └────┴────┴────┘
               ┌────┬────┐    ┌────┬────┐
               │    │    │    │BsW │DeW │
               └────┴────┘    └────┴────┘

  ←W/→W = word left/right    SelB/SelF = select word back/fwd
  Sel = select line          BsW/DeW = backspace/delete word

EDIT (hold Tab) - editing operations
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │ F← │Find│ F→ │                    │ {  │ }  │    │
┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
│All │Cut │Copy│Pste│    │          │ ←  │ ↓  │ ↑  │ →  │    │
└────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
     │    │Undo│Redo│                    │ [  │ ]  │    │
     └────┴────┴────┘                    └────┴────┴────┘
               ┌────┬────┐    ┌────┬────┐
               │░░░░│    │    │Bsp │Del │
               └────┴────┘    └────┴────┘

  F←/F→ = find prev/next     Combos: Copy+Pste = Save

FUN (hold Spc) - function keys
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │    │    │    │                    │ F7 │ F8 │ F9 │
┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
│    │    │    │    │    │          │    │ F4 │ F5 │ F6 │    │
└────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
     │    │    │    │                    │ F1 │ F2 │ F3 │
     └────┴────┴────┘                    └────┴────┴────┘
               ┌────┬────┐    ┌────┬────┐
               │    │░░░░│    │BsW │DeW │
               └────┴────┘    └────┴────┘

  Combos: F7+F8 = F10    F8+F9 = F11    F7+F8+F9 = F12

SYS (hold N or Bsp) - system, mouse, media
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │Play│ M4 │ M5 │                    │Mute│Vol-│Vol+│
┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
│End │Wh→ │Wh↑ │Wh↓ │Wh← │          │Ms← │░░N░│Ms↑ │Ms→ │Home│
└────┼────┼────┼────┼────┘          └────┼Ms↓─┼────┼────┼────┘
     │Mctl│Bri-│Bri+│                    │RGB │Zm- │Zm+ │
     └────┴────┴────┘                    └────┴────┴────┘
               ┌────┬────┐    ┌────┬────┐
               │ M2 │ M1 │    │░░░░│    │
               └────┴────┘    └────┴────┘

  Wh = scroll wheel    Ms = mouse cursor    Bri = brightness    Zm = zoom
  Mctl = mission control    M1/M2 = mouse buttons    M4/M5 = back/forward

  Combos:
    Wh↑+Wh↓ = Accel 1         Wh→+Wh↑+Wh↓ = Accel 0
    Play+M4+M5 = Toggle Autocorrect
    Mctl+Bri-+Bri+ = Toggle Sentence Case

ROS (hold G) - ROS2 teleop_twist_keyboard
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │    │    │    │                    │ U  │ I  │ O  │
┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
│    │    │    │    │░░G░│          │    │ J  │ K  │ L  │    │
└────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
     │    │    │    │                    │ M  │ ,  │ .  │
     └────┴────┴────┘                    └────┴────┴────┘
               ┌────┬────┐    ┌────┬────┐
               │    │    │    │    │    │
               └────┴────┘    └────┴────┘

UNI (hold P) - French unicode characters
     ┌────┬────┬────┐                    ┌────┬────┬────┐
     │ ë  │ ï  │░░P░│                    │ ê  │ â  │ û  │
┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
│ «  │ »  │    │    │    │          │ ù  │ è  │ à  │ é  │ ç  │
└────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
     │    │    │    │                    │ ô  │ î  │ œ  │
     └────┴────┴────┘                    └────┴────┴────┘
               ┌────┬────┐    ┌────┬────┐
               │    │    │    │    │    │
               └────┴────┘    └────┴────┘
```
