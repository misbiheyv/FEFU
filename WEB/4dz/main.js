// Task 1

let side = prompt("Введите размер стороны квадрата: ", '');

if( side <= 0 ){
    alert("Введите корректное значение");
} else {
    let S = side*side;
    alert("S = " + S);
}

// Task 2

// Function
function factorial(n){
    let result = 1;
    while(n){
        result *= n--;
    }
    return result;
}

// Main

let x = prompt("cos(x)-?\nx = ", '');
let n = prompt("С точностью до какого члена вы хотите разложить функцию? ", '');
let cos = 0;

for(let i = 0; i < n; i++){
    cos += Math.pow(-1, i) * Math.pow(x, 2*i)/factorial(2*i);
}

alert("cos(x) = " + cos + " + O(x^(2n+1))");

// Task 3

let M =[['','','','','','',''],
        ['','','','','','',''],
        ['','','','','','',''],
        ['','','','','','',''],
        ['','','','','','','']];


for(let i = 0; i < 5; i++){
    for(let j = 0; j < 7; j++){
        M[i][j] = i+j;
    }
}

for(let i = 0; i < M.length; i++) {
    for(let j = 0; j < M.length; j++) {
        if (j == M.length - 1)
            document.write(M[i][j]);
        else
            document.write(M[i][j] + ", ");
    }
    document.write("<br>");
}

// Task 4
