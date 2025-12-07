import fs from "fs";
const readInput = () => {
  const input = fs.readFileSync("day2_input.txt", "utf-8").trim();
  const data = input
    .split(",")
    .map((x: string) => x.split("-").map((y) => Number(y)));
  return data;
};

const data = readInput();

let sum = 0;

data.forEach((pair) => {
  const [start, end] = pair;
  for (let numberToCheck = start; numberToCheck <= end; numberToCheck++) {
    const numberAsString = String(numberToCheck);
    for (let len = 1; len < numberAsString.length; len++) {
      if (numberAsString.length % len !== 0) continue;
      const sub = numberAsString.slice(0, len);
      const regex = new RegExp(sub, "gi");
      const occurences = numberAsString.match(regex)?.length || 0;
      if (occurences * len === numberAsString.length) {
        sum += numberToCheck;
        break;
      }
    }
  }
});

console.log("Sum:", sum);
