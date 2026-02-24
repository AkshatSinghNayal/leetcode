int find(int par[], int x) {
    // add code here
    if(par[x]==x) return x;
    return par[x]=find(par, par[x]);
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int ulp_x=find(par, x);
    int ulp_z=find(par, z);
    if(ulp_x!=ulp_z){
        par[ulp_x]=ulp_z;
    }
}