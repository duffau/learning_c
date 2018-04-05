float absolute(float x);
float numDerivative(float (*func)(float), float x, float h);
float NewtonRaphson(float (*func)(float), float target, int maxIterations, float threshold);
