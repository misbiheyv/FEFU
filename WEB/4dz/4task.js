function getRandomInt(min, max){
    let rand = min + Math.random() * (max - min);
    return Math.floor(rand);
}
function getArray(n) {

    for (let i = 0; i < n; i++) {
        M[i] = [];
        for (let j = 0; j < n; j++) {
            M[i][j] = getRandomInt(1, 50);
        }
    }

    for (let i = 0; i < M.length; i++) {
        for (let j = 0; j < M.length; j++) {
            if (j == M.length - 1)
                document.write(M[i][j]);
            else
                document.write(M[i][j] + " ");
        }
        document.write("<br>");
    }
}

function getResultArray(a){

    let tempArr = [];

    for(let low = 0, high = a.length-1; low < high; low++, high--){
        tempArr[0] = a[low];
        a[low] = a[high];
        a[high] = tempArr[0];
    }

    for(let i = a.length-1; i >= 0; i--){
        a[i] = a[i].reverse();
        i--;
    }

    for (let i = 0; i < a.length; i++) {
        for (let j = 0; j < a.length; j++) {
            document.writeln(a[i][j] + " ");
        }
        document.writeln("<br>");
    }
}
    }

    for (let i = 0; i < a.length; i++) {
        for (let j = 0; j < a.length; j++) {
                document.writeln(a[i][j] + " ");
        }
        document.writeln("<br>");
    }
}

let M = [];
let n = prompt('разряд матрицы: ','');
getArray(n);
document.write("<br>");

getResultArray(M);
