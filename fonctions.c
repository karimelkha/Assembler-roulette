#include <stdio.h>
#include <stdlib.h>

void couleurNumeroGagnant (int numero_gagnant, char couleur[5]){

     if(numero_gagnant == 0)
        exit(-1);

    else if(numero_gagnant <= 10 || ( numero_gagnant >18 && numero_gagnant < 29)){

        if(numero_gagnant%2 == 0)
            sprintf(couleur,"noir");
        else
            sprintf(couleur,"rouge");
    }

    else if((numero_gagnant > 10 && numero_gagnant < 19)|| numero_gagnant > 28){
        if(numero_gagnant%2 == 0)
            sprintf(couleur,"rouge");
        else
            sprintf(couleur,"noir");
    }
  printf("%s !\n", couleur);   
}


int calculSommeFinale(int cash, int mise, int typeMise, int numero_gagnant, char couleur[5], int numero_choisi){


    if( typeMise == 1){     // si le joueur a misé un plein
        if(numero_gagnant == numero_choisi)
            cash = cash + 35*mise + mise;
    }

    else if(typeMise == 2){ // si le joueur a misé un cheval
    	if(numero_gagnant == numero_choisi || numero_gagnant == numero_choisi+3)
    		cash = cash + 17*mise + mise;
    }

    else if(typeMise == 3){ // si le joueur a misé une transversale
    	if(numero_gagnant == numero_choisi || numero_gagnant == numero_choisi+1 || numero_gagnant == numero_choisi+2 )
    		cash = cash + 11*mise + mise;
    }

    else if(typeMise == 4){ // si le joueur a misé le carré
    	if(numero_gagnant == numero_choisi || numero_gagnant == numero_choisi+1 || numero_gagnant == numero_choisi+3 || numero_gagnant == numero_choisi+4)
    		cash = cash + 8*mise + mise;
    }

    else if(typeMise == 5){ // si le joueur a misé un sizain
    	for (int i = 0; i < 6; ++i){
    		if(numero_gagnant == numero_choisi+i)
    			cash = cash + 5*mise + mise;
    	}
    }

    else if(typeMise == 6){ // si le joueur a misé rouge
    	if(couleur == "rouge")
    		cash = cash + mise + mise;
    }

    else if(typeMise == 7){ // si le joueur a misé noir
    	if(couleur == "noir")
    		cash = cash + mise + mise;
    }
  
  	else if(typeMise == 8){ // si le joueur a misé pair
  		if(numero_gagnant%2 == 0){
  			cash = cash + mise + mise;
        printf("blalalallala\n");
      }
  	}

  	else if(typeMise == 9){ // si le joueur a misé impair
  		if(numero_gagnant%2 != 0){
        printf("zejdnnsdnjsdj\n");
  			cash = cash + mise + mise;
      }
  	}

  	else if(typeMise == 10){ // si le joueur a misé manque
  		if(numero_gagnant >= 1 && numero_gagnant<= 18)
  			cash = cash + mise + mise;
  	}

  	else if(typeMise == 11){ // si le joueur a misé passe 
  		if(numero_gagnant >= 19 && numero_gagnant <= 36)
  			cash = cash + mise + mise;
  	}

  	else if(typeMise == 12){ // si le joueur a misé DP
  		if(numero_gagnant >= 1 && numero_gagnant <= 12)
  			cash = cash + 2*mise + mise;
  	}

  	else if(typeMise == 13){ // si le joueur a misé DM
  		if(numero_gagnant >= 13 && numero_gagnant <= 24)
  			cash = cash + 2*mise + mise;
  	}

  	else if(typeMise == 14){ // si le joueur a misé DD
  		if(numero_gagnant >= 25 && numero_gagnant <=36)
  			cash = cash + 2*mise + mise;
  	}

  	else if(typeMise == 15){ // si le joueur a misé Douzaines à cheval

  		if(numero_choisi == 1 && numero_gagnant >= 1 && numero_gagnant <= 24)
  			cash = cash + 0,5*mise + mise;
  		else if(numero_choisi == 13 && numero_gagnant >= 13 && numero_gagnant <= 36)
  			cash = cash + 0,5*mise + mise;

  	}

  	else if(typeMise == 16){ // si le joueur a misé colonne

  		if(numero_choisi == 1){
  			for (int j = 1 ; j < 12 ; j+=3){
  				if(numero_gagnant == j)
  					cash = cash + 0,5*mise + mise;
  			}
  		}
  		else if(numero_choisi == 2){
  			for(int k = 2; k < 13; k+=3){
  				if(numero_gagnant == k)
  					cash = cash + 0,5*mise + mise;
  			}

  		}
  		else if(numero_choisi == 3){
  			for (int l = 3; l < 14; l+=3){
  				if(numero_gagnant == l)
  					cash = cash + 0,5*mise + mise;
  			}

  		}

  	}

  	else if(typeMise == 17){ // si le joueur a misé colonne à cheval

  		  	if(numero_choisi == 1){

  			for (int j = 1 ; j < 12 ; j+=3){
  				if(numero_gagnant == j)
  					cash = cash + 0,5*mise + mise;
  			}
  			for(int k = 2; k < 13; k+=3){
  				if(numero_gagnant == k)
  					cash = cash + 0,5*mise + mise;
  			}
  		}

  		else if(numero_choisi == 2){

  			for(int k = 2; k < 13; k+=3){
  				if(numero_gagnant == k)
  					cash = cash + 0,5*mise + mise;
  			}
  			for (int l = 3; l < 14; l+=3){
  				if(numero_gagnant == l)
  					cash = cash + 0,5*mise + mise;
  			}
  		}

  	}


  return cash; 
}


