const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

readline.question("0~255 사이의 정수 입력: ", (input) => {
  const num = parseInt(input);
  if (isNaN(num) || num < 0 || num > 255) {
    console.log("잘못된 입력입니다.");
    readline.close();
    return;
  }

  const binary = num.toString(2).padStart(8, "0");
  const onesCount = binary.split("").filter((ch) => ch === "1").length;
  const upper4 = binary.substring(0, 4);

  console.log(`입력된 숫자: ${num}`);
  console.log(`2진수(8비트): ${binary}`);
  console.log(`1의 개수: ${onesCount}`);
  console.log(`상위 4비트: ${upper4}`);
  readline.close();
});
