## Pluck

Proper implementation of Pluck's (and Bug Bite's) move effect in FR.

> The user pecks the target. If the target is holding a Berry, the user eats it and gains its effect.

### What do I do before I build this?

If necessary, change `move_scripts` in `constants.s`. If this table hasn't been repointed, changing it won't necessary.

You may need to change `EFFECT_PLUCK` in `constants.s`. This is the move effect that will be assigned to Pluck (and Bug Bite) in move editor, so make sure you go with something otherwise unused. Note that if you haven't repointed `move_scripts`, you shouldn't set `EFFECT_PLUCK` above 213.

If you're using the updated Sitrus Berry effect, make sure you uncomment (i.e. remove the `//`) from `#define UPDATED_SITRUSBERRY_EFFECT` in `src/global.h`. To be clear, this will only update the Sitrus Berry effect (to recover 25% HP) in the context of this particular move effect.

The build script will search for adequate free space, but if you need to insert the code in a particular place, you can tell it where to start looking by modifying `free-space` in `config.ini`. If the given address is acceptable (i.e. is word-aligned and has enough bytes of free space), it will be inserted there.

### How do I build this?

Click [here](scripts/makinoa/README.md) for build instructions.

### What do I do after I build this?

Open a move editor and go to Pluck. Make sure that:

1. The move's effect matches what you set as `EFFECT_PLUCK`.
2. The move's effect accuracy is set to 100%. Effect accuracy is not the same thing as regular accuracy.

Naturally, do the same for Bug Bite.

### Anything else I should know?

The code determines what is and isn't a berry based on the item's pocket. So, if you add custom berries not in the original game, as long as they're assigned to the Berry Pouch, they'll still be recognized and eaten (though they won't have any additional effects unless they reuse the same effect as one of the vanilla berries).

The code has no support for the Simple or Contrary abilities.

The text for `[ATTACKER] ate [DEFENDER]'s [BERRY]!` will not display for Player 2 during a link battle; the textbox will just look empty during the window of time where it would normally be displayed. This seems to be an issue with Jambo's battle string loader hack. To be clear, all other aspects of Pluck's effect (including, for example, healing by Plucking an Oran Berry) work and display properly on both games.