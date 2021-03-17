#include "snowman.hpp"


namespace ariel{

    const int Hat_kind = 0;
    const int nose_kind = 1;
    const int Leye_kind = 2;
    const int Reye_kind = 3;
    const int Lhand_kind = 4;
    const int Rhand_kind = 5;
    const int Torso_kind = 6;
    const int Base_kind = 7;
    const int input_length = 8;

    void throwException(){
        throw std::invalid_argument("Invalid code");
    }
    
    std::string hat (char hat_type){
        switch (hat_type){
            case '1': return " _===_";
            break;
            case '2': return "  ___ \n .....";
            break;
            case '3': return "   _  \n  /_\\ ";
            break;
            case '4': return " ___\n (_*_)";
            break;
            default : return "";
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
            default: return "";
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
            case '4': return " ";
            break;
            default: return "";
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
            case '4': return " ";
            break;
            default: return "";
        }
    }

    std::string Lhand (char Rhand){
        switch (Rhand){
            case '1': return "<";
            break;
            case '2': return "\\";
            break;
            case '3': return "/";
            break;
            case '4': return " ";
            break;
            default: return "";
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
            default: return "";
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
            default: return "";
        }
    }

    
    void check_input(std::string input){
        if(input.length()!=input_length)
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
        std::string snowman =hat(input.at(Hat_kind))+"\n";     // hat
        if(input.at(Lhand_kind)!= '2')  //Left hand is down!
        {
            snowman = snowman + " " + "("+ eyes(input.at(Leye_kind));      // left eye
            snowman = snowman + nose(input.at(nose_kind));      // nose
            snowman = snowman + eyes(input.at(Reye_kind))+")";      // right eye
            if(input.at(Rhand_kind)!= '2') //Left and right hands are down!
            {
                snowman = snowman +"\n"+ Lhand(input.at(Lhand_kind));     // left arm
                snowman = snowman +  "("+Torso(input.at(Torso_kind))+")";     // torso
                snowman = snowman + Rhand(input.at(Rhand_kind))+"\n";     // right arm
            }
            else{ //Left hand is down and right hand is up.
                snowman = snowman + Rhand(input.at(Rhand_kind))+"\n";     // right arm
                snowman = snowman + Lhand(input.at(Lhand_kind));     // left arm
                snowman = snowman + "("+Torso(input.at(Torso_kind))+")\n";     // torso
            }
        }
        else{ //Left hand is up
        snowman = snowman + Lhand(input.at(Lhand_kind));     // left arm
        snowman = snowman + "("+ eyes(input.at(Leye_kind));      // left eye
        snowman = snowman + nose(input.at(nose_kind));      // nose
        snowman = snowman + eyes(input.at(Reye_kind))+")";      // right eye
            if(input.at(Rhand_kind)!= '2') //Left is up and right hand is down!
            {
                snowman = snowman + "\n "+ "("+Torso(input.at(Torso_kind))+")";     // torso
                snowman = snowman + Rhand(input.at(Rhand_kind))+"\n";     // right arm
            }
            else{
                snowman = snowman  +Rhand(input.at(Rhand_kind))+"\n";     // right arm  
                snowman = snowman +" ("+Torso(input.at(Torso_kind))+")\n";     // torso
            }
        }        
        // snowman = snowman + Lhand(input.at(4))+"(";     // left arm
        // snowman = snowman + eyes(input.at(2));      // left eye
        // snowman = snowman + nose(input.at(1));      // nose
        // snowman = snowman + eyes(input.at(3))+")";      // right eye
        // snowman = snowman + Rhand(input.at(5))+"\n";     // right arm
        // snowman = snowman + "("+Torso(input.at(6))+")\n";     // torso
        snowman = snowman + " "+ "("+Base(input.at(Base_kind))+")";      // base
        return snowman;
    }
}
