//
// Created by Juan Diego Castro Padilla on 19/05/22.
//

#ifndef S9_SFML_RENDER_H
#define S9_SFML_RENDER_H

#include <memory>

template<typename T>
class render {

private:

    std::shared_ptr<T> data;
    inline static render<T>* unique_instance {};

    template<typename ... Params>
    explicit render(Params... params):data(std::make_shared<T>(params...)){
    }

public:

    template<typename ... Params>
    static render<T>* get_instance(Params... params){

        if (unique_instance == nullptr){
            unique_instance = new render<T>(params...);
        }
        return unique_instance;
    }

    std::shared_ptr<T> get(){
        return data;
    }

};


#endif //S9_SFML_RENDER_H
