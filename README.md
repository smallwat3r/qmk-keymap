# Smallwat3r's QMK keymap

Custom 26 keys layout with minimal strain on pinky fingers for the [Smallcat](https://github.com/smallwat3r/smallcat) keyboard.

Highly relying on combos. I'm using very light switches (Ambients Nocturnal from Kailh, 20g), which makes it very comfortable.

I use `./scripts/copy-boards` to copy the Smallcat keyboard configs to my local QMK firmware repository.

Compile firmware
```
qmk compile -kb smallcat/26 -km default 
```

Flash firmware
```
qmk flash -kb smallcat/26 -km default 
```

![keymap](./images/keymap.png)
