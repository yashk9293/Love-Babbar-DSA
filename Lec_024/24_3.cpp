// Pigeonhole Principle
// https://youtu.be/Hlr3CLVhvGg





// Catalan Number
// c0 = 1
// c1 = 1
// c2 = c0.c1 + c1.c0 = 1.1 + 1.1 = 2
// c3 = c0.c2 + c1.c1 + c2.c0 = 1.2 + 1.1 + 2.1 = 5
// c4 = c0.c3 + c1.c2 + c2.c1 + c3.c0 = 1.5 + 1.2 + 2.1 + 5.1 = 14


int arr[n+1];
arr[0]=1;
arr[1]=1;
for(int i=2; i<n; i++) {
    for(j=0; j<i; j++) {
        arr[i]= arr[j] * arr[i-j-1];
    }
}
for(int i=0; i<n; i++) {
    cout<<arr[i]<<" "
}




// Inclusive/Exclusive Principle
// https://youtu.be/IW4hJEgZLWI