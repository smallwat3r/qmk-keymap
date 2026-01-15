# Smallwat3r's QMK Keymap

Custom 26-key layout for the [Smallcat](https://github.com/smallwat3r/smallcat) keyboard, designed to minimize pinky strain.

Uses very light switches (Kailh Ambients Nocturnal, 20g) and relies heavily on combos for missing keys.

## Building

```
make          # Show available targets
make all      # Build all keyboards
make 26       # Build smallcat/26
make uni      # Build smallcat/uni
make flash-26 # Flash smallcat/26
make flash-uni# Flash smallcat/uni
make format   # Format code with clang-format
make clean    # Clean build artifacts
```

Compiled UF2 files are placed in the `uf2/` directory.

## Smallcat keymap

Legend: `░░░` = held key to activate layer

```
BASE
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │ L │ D │ P │               │ F │ O │ U │
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│ W │ R │ T │ S │ G │       │ Y │ N │ A │ E │ I │
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │ K │ M │ C │               │ H │ , │ . │
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │Tab│Spc│   │Bsp│Ent│
            └───┴───┘   └───┴───┘

  Hold modifiers:
    Left:  W=Sft  R=SYM2  T=NUM  S=NAV  G=ROS  P=UNI
           K=Ctl  M=Alt   C=Gui  Tab=EDIT  Spc=FUN
    Right: I=Sft  E=SYM2  N=SYS  H=Gui  ,=Alt  .=Ctl
           Bsp=SYS  Ent=SYM

  Combos (left):
    L+D+P = Z    D+P = Q      L+P = [      K+C = (
    R+T = B      K+M = X      M+C = J      T+C = V
    R+S = "sh"   T+S = "th"   W+S = "wh"   R+T+S = OSM Sft
    W+C = ".com"              W+G = "smallwat3r"

  Combos (right):
    N+A+E = Esc  N+E = '      F+U = ]      H+. = )
    H+A = _      H+, = -      ,+. = ;
    U+N = "you"  H+E = "ion"  N+I = "ing"

  Combos (both):
    S+N = Caps Word           G+Y = Screenshot

NUM (hold T) - number pad
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │   │   │   │               │ 7 │ 8 │ 9 │
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│   │   │░T░│ . │   │       │000│ 4 │ 5 │ 6 │ 0 │
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │   │   │ , │               │ 1 │ 2 │ 3 │
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │   │Spc│   │Bsp│Del│
            └───┴───┘   └───┴───┘

SYM (hold Ent) - symbols
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │ @ │ £ │ $ │               │ \ │ / │ ? │
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│ * │ - │ = │ " │ % │       │ ! │ : │ # │ ~ │ | │
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │ + │ & │ ` │               │ < │ > │-> │
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │   │Spc│   │   │░░░│
            └───┴───┘   └───┴───┘

  Combos: £+$ = €    =+" = \"\"\"    &+` = ```    *+Spc = indent

SYM2 (hold R or E) - symbols with home row passthrough for rolls
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │ @ │ £ │ $ │               │ \ │ / │ ? │
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│ * │░r░│ = │ " │ % │       │ ! │ : │ a │░e░│ | │
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │ + │ & │ ` │               │ < │ > │-> │
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │   │Spc│   │   │   │
            └───┴───┘   └───┴───┘

NAV (hold S) - navigation and brackets
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │   │   │   │               │ { │ } │   │
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│End│   │NV2│░S░│   │       │ ← │ ↓ │ ↑ │ → │Hom│
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │   │   │   │               │ [ │ ] │   │
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │M2 │M1 │   │Bsp│Del│
            └───┴───┘   └───┴───┘

NAV2 (hold S + NV2) - word navigation and selection
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │   │   │   │               │   │   │   │
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│   │   │░░░│░S░│   │       │←W │SelB│SelF│→W │   │
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │   │   │   │               │Sel│   │   │
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │   │   │   │BsW│DeW│
            └───┴───┘   └───┴───┘

  ←W/→W = word left/right    SelB/SelF = select word back/fwd
  Sel = select line          BsW/DeW = backspace/delete word

EDIT (hold Tab) - editing operations
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │F← │Fnd│F→ │               │ { │ } │   │
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│All│Cut│Cpy│Pst│   │       │ ← │ ↓ │ ↑ │ → │   │
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │   │Und│Red│               │ [ │ ] │   │
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │░░░│   │   │Bsp│Del│
            └───┴───┘   └───┴───┘

  F←/F→ = find prev/next     Combos: Cpy+Pst = Save

FUN (hold Spc) - function keys
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │   │   │   │               │F7 │F8 │F9 │
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│   │   │   │   │   │       │   │F4 │F5 │F6 │   │
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │   │   │   │               │F1 │F2 │F3 │
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │   │░░░│   │BsW│DeW│
            └───┴───┘   └───┴───┘

  Combos: F7+F8 = F10    F8+F9 = F11    F7+F8+F9 = F12

SYS (hold N or Bsp) - system, mouse, media
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │Ply│M4 │M5 │               │Mut│Vl-│Vl+│
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│End│Wh→│Wh↑│Wh↓│Wh←│       │Ms←│░N░│Ms↑│Ms→│Hom│
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │Mct│Br-│Br+│               │RGB│Zm-│Zm+│
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │M2 │M1 │   │░░░│   │
            └───┴───┘   └───┴───┘

  Wh = scroll wheel    Ms = mouse cursor    Br = brightness    Zm = zoom
  Mct = mission control    M1/M2 = mouse buttons    M4/M5 = back/forward

  Combos:
    Wh↑+Wh↓ = Accel 1         Wh→+Wh↑+Wh↓ = Accel 0
    Ply+M4+M5 = Autocorrect On
    Mct+Br-+Br+ = Autocorrect Off

ROS (hold G) - ROS2 teleop_twist_keyboard
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │   │   │   │               │ U │ I │ O │
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│   │   │   │   │░G░│       │   │ J │ K │ L │   │
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │   │   │   │               │ M │ , │ . │
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │   │   │   │   │   │
            └───┴───┘   └───┴───┘

UNI (hold P) - French unicode characters
    ┌───┬───┬───┐               ┌───┬───┬───┐
    │ ë │ ï │░P░│               │ ê │ â │ û │
┌───┼───┼───┼───┼───┐       ┌───┼───┼───┼───┼───┐
│ « │ » │   │   │   │       │ ù │ è │ à │ é │ ç │
└───┼───┼───┼───┼───┘       └───┼───┼───┼───┼───┘
    │   │   │   │               │ ô │ î │ œ │
    └───┴───┴───┘               └───┴───┴───┘
            ┌───┬───┐   ┌───┬───┐
            │   │   │   │   │   │
            └───┴───┘   └───┴───┘
```

Note: The keymap image below (August 2025) might be slightly out of date, but most of it is still accurate.

![keymap](./images/keymap.png)
