#include "snowman.hpp"


namespace ariel{

    void throwException(){
        throw std::invalid_argument("Invalid code");
    }
    
    std::string hat (char hat_type){
        switch (hat_type){
            case '1': return " _===_\n";
            break;
            case '2': return "  ___ \n .....";
            break;
            case '3': return "   _  \n  /_\\ ";
            break;
            case '4': return "  _ \n (_*_)";
            break;
        }
    }

        std::string eyes (char Reye){
        switch (Reye){
            case '1': return ".";
            break;
            case '2': return "o";
            break;
            case '3': return "O";
            break;
            case '4': return "-";
            break;
        }
    }

    std::string nose (char nose){
        switch (nose){
            case '1': return ",";
            break;
            case '2': return ".";
            break;
            case '3': return "_";
            break;
            case '4': return "";
            break;
        }
    }

    std::string Rhand (char Rhand){
        switch (Rhand){
            case '1': return ">";
            break;
            case '2': return "/";
            break;
            case '3': return "\\";
            break;
            case '4': return "";
            break;
        }
    }

    std::string Lhand (char Rhand){
        switch (Rhand){
            case '1': return ">";
            break;
            case '2': return "\\";
            break;
            case '3': return "/";
            break;
            case '4': return "";
            break;
        }
    }

    std::string Torso (char Torso){
        switch (Torso){
            case '1': return " : ";
            break;
            case '2': return "] [";
            break;
            case '3': return "> <";
            break;
            case '4': return "   ";
            break;
        }
    }

    std::string Base (char Base){
        switch (Base){
            case '1': return " : ";
            break;
            case '2': return "\" \"";
            break;
            case '3': return "___";
            break;
            case '4': return "   ";
            break;
        }
    }

    
    void check_input(std::string input){
        if(input.length()!=8)
        {
          throwException();  
        }
        for(int i=0; i<input.length();i++)
        {
            if(input.at(i)<='0' || input.at(i)>'4')
            {
                throwException(); 
            }
        }

    }
    
    
    std::string snowman(int num){
        std::string input = std::to_string(num);     //112233441
        check_input(input);
        std::string snowman ="";
        snowman = snowman +hat(input.at(0))+"\n";      // hat
        if(input.at(4)!= '2')  //Left hand is down!
        {
            snowman = snowman + " " + "("+ eyes(input.at(2));      // left eye
            snowman = snowman + nose(input.at(1));      // nose
            snowman = snowman + eyes(input.at(3))+")\n";      // right eye
            snowman = snowman + Lhand(input.at(4));     // left arm
            if(input.at(5)!= '2') //Left and right hands are down!
            {
                snowman = snowman + " "+ "("+Torso(input.at(6))+")";     // torso
                snowman = snowman + Rhand(input.at(5))+"\n";     // right arm
            }
            else{ //Left hand is down and right hand is up.
                snowman = snowman + Rhand(input.at(5))+"";     // right arm
                snowman = snowman + " "+ "("+Torso(input.at(6))+")\n";     // torso
            }
        }
        else{ //Left hand is up
        snowman = snowman + Lhand(input.at(4));     // left arm
        snowman = snowman + "("+ eyes(input.at(2));      // left eye
        snowman = snowman + nose(input.at(1));      // nose
        snowman = snowman + eyes(input.at(3))+")\n";      // right eye
            if(input.at(5)!= '2') //Left is up and right hand is down!
            {
                snowman = snowman + " "+ "("+Torso(input.at(6))+")";     // torso
                snowman = snowman + Rhand(input.at(5))+"\n";     // right arm
            }
            else{
                snowman = snowman + Rhand(input.at(5))+"";     // right arm
                snowman = snowman + "("+Torso(input.at(6))+")\n";     // torso                
            }
        }        
        // snowman = snowman + Lhand(input.at(4))+"(";     // left arm
        // snowman = snowman + eyes(input.at(2));      // left eye
        // snowman = snowman + nose(input.at(1));      // nose
        // snowman = snowman + eyes(input.at(3))+")";      // right eye
        // snowman = snowman + Rhand(input.at(5))+"\n";     // right arm
        // snowman = snowman + "("+Torso(input.at(6))+")\n";     // torso
        snowman = snowman + " "+ "("+Base(input.at(7))+")";      // base
        return snowman;
    }
}