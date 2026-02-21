function countPrimeSetBits(left: number, right: number): number {
    let count : number = 0;
    for (let i : number = left; i <= right; i++) {
        let setBits = i.toString(2).split('1').length - 1;  
        if (isPrime(setBits)) 
            count++;
    }
    return count;
};

function isPrime(n : number) : boolean {
    if (n <= 1)
        return false;
    for (let i : number = 2; i * i <= n; i++) {
        if (n % i === 0) 
            return false;
    }
    return true;
}