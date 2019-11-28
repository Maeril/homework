"use strict";

// /* quicksort code */

let values = [];
let w = 10;
let states = [];
let instructions;
let numbers = [];

function setup() {
  createCanvas(windowWidth, windowHeight);
  instructions = loadStrings("output.txt");
  numbers = loadStrings("numbers.txt");
  values = new Array(floor(width / w));
  for (let i = 0; i < values.length; i++) {
    values[i] = random(height);
    states[i] = -1;
  }
  quickSort(values, 0, values.length - 1);
}

async function quickSort(arr, start, end) {
  if (start >= end) {
    return;
  }
  let index = await partition(arr, start, end);
  states[index] = -1;
  await Promise.all([
    quickSort(arr, start, index - 1),
    quickSort(arr, index + 1, end)
  ]);
}

async function partition(arr, start, end) {
  for (let i = start; i < end; i++) {
    states[i] = 1;
  }
  let pivotValue = arr[end];
  let pivotIndex = start;
  states[pivotIndex] = 0;
  for (let i = start; i < end; i++) {
    if (arr[i] < pivotValue) {
      await swap(arr, i, pivotIndex);
      states[pivotIndex] = -1;
      pivotIndex++;
      states[pivotIndex] = 0;
    }
  }
  await swap(arr, pivotIndex, end);
  for (let i = start; i < end; i++) {
    if (i != pivotIndex) {
      states[i] = -1;
    }
  }
  return pivotIndex;
}

function draw() {
  background(0);
  for (let i = 0; i < values.length; i++) {
    noStroke();
    if (states[i] == 0) { // rouge
      fill('#E0777D');
    } else if (states[i] == 1) { // vert
      fill('#D6FFB7');
    } else {
      fill(255);
    }
    rect(i * w, height - values[i], w, values[i]);
  }
}

async function swap(arr, a, b) {
  await sleep(50);
  let temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}


/* my code */
// var x;
// var y;
// var t = 0;
// let file = [];
// file = loadStrings('numbers.txt');


// function setup() {
//   createCanvas(400, 400);
//   print("file[0] = ", file[1]);
// }

// function preload() {
  // also tried moving the file and then
  // file = loadStrings("output_coord_cartesian.txt");
// }


// function draw() {
//   // some magic
// }

// function setup() {
//   createCanvas(500,150)
//   background(255,255,255)

//   line(100,0,400,0)
//   line(100,10,400,10)
//   line(100,20,400,20)
//   line(100,30,400,30)
//   line(100,40,400,40)
//   line(100,50,400,50)
//   line(100,60,400,60)
//   line(100,70,400,70)
//   line(100,80,400,80)
//   line(100,90,400,90)
// }

// function draw() {
//   background(0);

//   for(i = 0; i < instructions.length; i++) {
//     noStroke();
//     if (instructions[i] == 'sa')

//   }
//   ellipse(mouseX, mouseY, 80, 80);
// }
