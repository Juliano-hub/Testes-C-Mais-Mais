#ifndef FORMA_H
#define FORMA_H

class Forma{
    protected:
        double base;
        double altura;
    
    public:
        static int quant;
        Forma(double base, double altura){
            this->base = base;
            this->altura = altura;
        }

        // desconstrutor
        virtual ~Forma() = default;

        double GetBase(){
            return this->base;
            }
        double GetAltura(){
            return this->altura;
        }
        double GetQuant(){
            return this->quant;
            }
        double Area(){
            return this->base * this->altura;
        }
};

#endif /* FORMA_H */