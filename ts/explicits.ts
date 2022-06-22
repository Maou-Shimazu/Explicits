import {directories} from "../deps.ts"

// Game statistics

class Player {
    constructor(){};
    name: string = "";
    health: number = 0;
    attack: number = 0; 
    heal: number = 0;   
    powers: Map<string, number> = new Map<string, number>();
    deathMessage: Array<string> = new Array<string>();
    // iter(): any { for (let i (this.powers) ){
    //     console.log(i, x);
    // } };

    stats(): any {
        console.log(`Name: ${this.name}\nHealth: ${this.health}\nAttack: ${this.attack}\nPowers: ${this.powers.keys(), this.powers.values()}\n`);
    }
}

// class Monster {
    // name: string = "";
    // health: number = 0;
    // attack: number = 0; 
    // heal: number = 0;
    // powers: Map<string, number> = new Map<string, number>();
    // deathMessage: Array<string> = new Array<string>();
// }


export { Player, /*Monster*/ };