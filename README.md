# Smallwat3r's QMK keymap

Layout inspired from Graphite with some modifications in order to accommodate 26 keys and reduce usage of pinky fingers.

Highly relying on combos from the base layer. I'm currently using very light switches (Ambients Nocturnal from Kailh, 20g), which makes using combos very easy.

I use `./cp-smallcat` to copy the Smallcat keyboard configs onto my local QMK firmware repository.

Compile firmware
```
qmk compile -kb smallcat/26 -km default 
```

Flash firmware
```
qmk flash -kb smallcat/26 -km default 
```

![keymap](./images/keymap.png)

I'm using an implementation of Magic Key (❖):

| Sequence                 | First ❖ tap | Second ❖ tap |
|--------------------------|-------------|--------------|
| <kbd>a</kbd><kbd>❖</kbd> | about␣      |              |
| <kbd>b</kbd><kbd>❖</kbd> | because␣    | before␣      |
| <kbd>c</kbd><kbd>❖</kbd> | class␣      |              |
| <kbd>d</kbd><kbd>❖</kbd> | def␣        |              |
| <kbd>e</kbd><kbd>❖</kbd> | else␣       |              |
| <kbd>i</kbd><kbd>❖</kbd> | import␣     |              |
| <kbd>I</kbd><kbd>❖</kbd> | I'm␣        |              |
| <kbd>j</kbd><kbd>❖</kbd> | just␣       |              |
| <kbd>m</kbd><kbd>❖</kbd> | ment␣       |              |
| <kbd>n</kbd><kbd>❖</kbd> | nion␣       |              |
| <kbd>o</kbd><kbd>❖</kbd> | on't␣       |              |
| <kbd>r</kbd><kbd>❖</kbd> | return␣     |              |
| <kbd>s</kbd><kbd>❖</kbd> | sion␣       | sn't␣        |
| <kbd>t</kbd><kbd>❖</kbd> | tment␣      | thank        |
| <kbd>u</kbd><kbd>❖</kbd> | update␣     |              |
| <kbd>v</kbd><kbd>❖</kbd> | ver         |              |
| <kbd>w</kbd><kbd>❖</kbd> | what␣       | which␣       |
| <kbd>y</kbd><kbd>❖</kbd> | you         |              |
| <kbd>z</kbd><kbd>❖</kbd> | zero␣       |              |
| <kbd>,</kbd><kbd>❖</kbd> | ,␣but␣      |              |
| <kbd>.</kbd><kbd>❖</kbd> | ./          | ../          |
| <kbd>+</kbd><kbd>❖</kbd> | +=          |              |
| <kbd>-</kbd><kbd>❖</kbd> | -=          |              |
| <kbd>=</kbd><kbd>❖</kbd> | =>          |              |
