#pragma once
#include "EntityType.h"
#include "DialogueType.h"

static const char * monsterPlayerInteraction[MAX_CREATURE_TYPES][MAX_MONSTER_TYPES][MAX_DIALOGUE_TYPES]
{
	{
	//Monsters:

	//Slime
		{	"A slime jiggles around.",
			"The slime smacks you as hard as it can.",
			"The slime squishes apart."
		},

	//Imp
		{	"A mischievous imp is caught red-handed.",
			"The imp tries to outmaneuver you, getting hits where it can.",
			"The imp is outmatched by your strength."
		},

	//Leprechaun
		{
			"A leprechaun comes out with a fierce fighting stance. It won't give up its gold easily.",
			"The leprechaun brawls like a true irishman.",
			"The leprechaun runs away, cursing you out for taking his gold."
		},

	//Golem
		{	"A golem stands strong, like a boulder." ,
			"The golem swings his fist at you.",
			"The golem tumbles and breaks into pieces."
		},

	//Ghost
		{
			"A ghost stares beyond into space.",
			"The ghost scares you, and you take some damage from stress.",
			"The ghost disappears before your eyes."
		},

	//Demon
		{
			"A red-horned demon appears with a smirk.",
			"The demon summons a tridet and throws it at you.",
			"The demon slowly sinks back to the pit from where it came."
		},

	//Goblin
		{
			"A goblin tells you to give him your money.",
			"The goblin wildly swings his pocket knife at you.",
			"The goblin retreats quickly out of sight. "
		},

	//Pixie
		{
			"A rabid pixie flies towards you.",
			"The pixie picks you up with its magic dust and drops you.",
			"The pixie weakly flutters to the ground."
		},

	 //Mutant
		{
			"A menacing mutant stares intently at you.",
			"The mutant smacks you, pushing you with all his weight.",
			"The mutant disintegrates into a glowing green puddle."
		},

	//Vampire
		{
			"A sly vampire appears out of thin air.",
			"The vampire pierces your skin with its fangs.",
			"The vampire parishes as its heart has been pierced."
		},
	
	//Werewolf
		{
			"A werewolf stands in front of you, gnarling its teeth.",
			"The hairy beast thrashes you with its bone claws.",
			"The werewolf is knocked out, transforming into a human."
		},

	//Zombie
		{
			"A discolored, bloodied zombie straggles to you.",
			"The zombie bites your flesh thrashes his arms at you. ",
			"The zombie stops moving when as it get beheaded."
		},

	//Cyclops
		{
			"A cyclops give you the dirty eye.",
			"The cyclops swings his 10 foot club at you.",
			"The cyclops loses its sight and dies as a sword pierces its eye."
		},

	//Sasquatch
		{
			"A 10 foot ape with enormous feet appears before you.",
			"The sasquatch has incredible strength and speed in hand to hand combat.",
			"The sasquatch admits defeat as he is pinned and lets you go."
		},

	//Phoenix
		{
			"A firey phoenix appears before you.",
			"The phoenix scorches you with its flaming wings.",
			"The phoenix falls to the ground as it takes too much physical damage."
		},

	//Dragon
		{	"A dragon flies in with a gust of wind.",
			"The dragon spits fire in your direction and claws at you.",
			"The dragon collapses to the floor as you lay a fatal blow."
		}
	},

	{
	//Player reaction to:

	//Slime
		{
			"You hear a squishing noise.",
			"You continually jab at the slime's insides.",
			"You managed to be defeated by the slime."
		},

	//Imp
		{
			"You feel something coming out of your pocket...",
			"You land swift strikes against the imp.",
			"As you lay on the ground, you see the imp scavenging your things."
		},

	//Leprechaun
		{
			"You see a rainbow and a green figure approaching you.",
			"You commit to hand-to-hand combat with the leprechaun.",
			"The leprechaun does an irish jig around you as you lay on the ground."
		},

	//Golem
		{
			"You hear a clattering of stones. Something is stomping your way.",
			"You clash with the golem's hard exterior. You wear it down.",
			"K.O.! The heavy-handed golem defeats you with his strength."
		},

	//Ghost
		{
			"You feel something moving through you.",
			"You chant, telling the ghost to move on from this life.",
			"You fell to the same fate as the ghost. "
		},

	//Demon
		{
			"You feel a sinister force nearby.",
			"You scar the demon's body with a quick stab.",
			"You go down with the demon into the fiery pit from where it came."
		},

	//Goblin
		{
			"You see a green big-nosed figure hiding in a bush.",
			"You take advantage of your size and pummel the goblin.",
			"The stab wounds takes its toll, and you lay incapacitated."
		},

	//Pixie
		{
			"You feel some sort of your dust falling on your face.",
			"You cripple the pixie's wing a little bit.",
			"The impact of the ground kills you."
		},

	//Mutant
		{
			"You see a bright green glow nearby.",
			"You slice off the mutant's limb, as they grow back.",
			"The mutant's relentless attacks kills you."
		},

	//Vampire
		{
			"You see a dead man laying on the floor with his blood drained.",
			"You aim for the vampire's heart and continually jab at it.",
			"Your blood gets drained and you die as the vampire overwhelms you."
		},

	//Werewolf
		{
			"You notice the moonlight shining and hear a loud howl.",
			"You wrestle with the grizzly beast.",
			"The werewolf sprints away as you bleed to death."
		},

	//Zombie
		{
			"You hear moaning and smell rotting flesh.",
			"You try to mutilate the zombie, aiming for its head.",
			"The zombie looks over your tasty carcass."
		},

	//Cyclops
		{
			"You feel the earth quake as something stomps towards you.",
			"You aim at the cyclops feet, hoping to get him to the ground.",
			"You become a splat on the ground as the cyclops crushes you."
		},

	//Sasquatch
		{
			"Out of the corner of your eye, you see a tall figure in the woods.",
			"You try to grapple the sasquatch, and pin him.",
			"You are outmatched, and you are too exhausted to continue your journey."
		},

	//Phoenix
		{
			"You feel an immense heat and see something shining bright.",
			"You try to stab at the center of the phoenix, its only physical body part.",
			"You catch on fire, and are consumed by the phoenix's flames."
		},

	//Dragon
		{
			"You hear a thunderous roar and a powerful beat of wings.",
			"You jab at the dragon, trying to pierce its scales.",
			"You are consumed by the dragon's flames."
		}
	}
};