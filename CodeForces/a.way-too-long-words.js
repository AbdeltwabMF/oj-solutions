// https://codeforces.com/contest/71/problem/A

function split(s) {
    return (s[0] + (s.length - 2) + s[s.length - 1]);
}

function main() {
    var n = parseInt(readline());
    
    for(var i = 0; i < n; ++i) {
        var str = readline();
        if(str.length > 10) print(split(str));
        else print(str);
    }
}

main();