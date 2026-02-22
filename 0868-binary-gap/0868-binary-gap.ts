function binaryGap(n: number): number {
    const binary = n.toString(2);
    const onePositions: number[] = [];
    for (let i = 0; i < binary.length; i++) {
        if (binary[i] === '1')
            onePositions.push(i);
    }
    if (onePositions.length < 2)
        return 0;
    let maxDistance = 0;
    for (let i = 1; i < onePositions.length; i++) {
        const distance = onePositions[i] - onePositions[i - 1];
        maxDistance = Math.max(maxDistance, distance);
    }
    return maxDistance;
};