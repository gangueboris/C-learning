# include"cesar.c"

int main(){
    // Definition de notre tableau tabFrequence
    int tabFrequence[26] = {'0'} ;

    // Definition de la phrase de test en question ou lettre de test
    char phrase[] = "ZNVGER PBEORNH, FHE HA NEOER CREPUR, GRANVG RA FBA ORP HA SEBZNTR. ZNVGER ERANEQ CNE Y'BQRHE NYYRPUR, YHV GVAG N CRH CERF PR YNATNTR : RG OBAWBHE ZBAFVRHE QH PBEORNH. DHR IBHF RGRF WBYV! DHR IBHF ZR FRZOYRM ORNH! FNAF ZRAGVE, FV IBGER ENZNTR FR ENCCBEGR N IBGER CYHZNTR IBHF RGRF YR CURAVK QRF UBGRF QR PRF OBVF. N PRF ZBGF YR PBEORNH AR FR FRAG CNF QR WBVR; RG CBHE ZBAGERE FN ORYYR IBVK, VY BHIER HA YNETR ORP YNVFFR GBZORE FN CEBVR. YR ERANEQ F'RA FNVFVG RG QVG : ZBA OBA ZBAFVRHE, NCERARM DHR GBHG SYNGGRHE IVG NH QRCRAF QR PRYHV DHV Y'RPBHGR : PRGGR YRPBA INHG OVRA HA SEBZNTR FNAF QBHGR. YR PBEORNH UBAGRHK RG PBASHF WHEN ZNVF HA CRH CYHF GNEQ, DH'BA AR Y'L CERAQENVG CYHF";
    //char phraseChif[2000] ;
    int phraseLen ;
    int cleDecalage ;

    // Test de la fonction chiffrement avec une cle = 2
    
    printf("le nom a chiffrer est:%s\n",phrase);
    // Test de la fonction dechiffrement
   //char dechif = dechiffrement(chif, 2) ;

    // Chiffrement d'une phrase
    phraseLen = strlen(phrase);
    for(int i = 0 ; i < phraseLen ; i++){
        char chiff = chiffrement(phrase[i],6) ;
        phrase[i] = chiff ;
    }

   // affichage de la phrase chiffré
    printf("le nom dechiffrer est:%s\n",phrase) ;

   // Test de la fonction analyse  frequence
    analyserFrequence(phrase, tabFrequence) ;
   
   // Test de la fonction calcul Cle
    cleDecalage = calculerCle(tabFrequence) ; 
    printf("la cle de decalage est:%d\n",cleDecalage) ;
   
return 0 ;
    
}
