class H2O {
    mutex mtx;
    condition_variable cv;
    int hyd = 0, oxy = 0;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx); // lock the mutex
        
        // if hyd < 2 and oxy <= 1 then release the hyd
        // else wait
        
        cv.wait(lock, [this] { return hyd<2; });
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        
        // if OH then reset both to 0
        // else add 1 H
        
        if(oxy == 1 && hyd == 1) {oxy = 0; hyd = 0;}
        else hyd++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx); // lock the mutex
        
        // if hyd <= 2 and oxy == 0 then release the oxy
        // else wait
        
        cv.wait(lock, [this] { return oxy==0; });
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        
        // if HH then reset both to 0 
        // else add 1 O
        
        if(hyd == 2) {oxy = 0; hyd = 0;}
        else oxy++;
        cv.notify_all();
    }
};