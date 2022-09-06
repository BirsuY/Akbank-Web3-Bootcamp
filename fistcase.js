//birsuyilmaz

console.log(oddishOrEvenish(43));
console.log(oddishOrEvenish(373));
console.log(oddishOrEvenish(4433));

//This is a function which creates an integer array from the number's digits.
function numberToArray(num) {
    let digits = num.toString().split("");
    return digits.map(x => parseInt(x));
}

//This is a function which returns Odd or Even based on the total of the number's digits
function oddishOrEvenish(num){
    let total = 0;
    var number = numberToArray(num);

    for (let i = 0; i < number.length; i++) {
        total += number[i];
      }
    if(total % 2 == 0){
        return "Even";
    }
    return "Odd";
}
//birsuyilmaz
