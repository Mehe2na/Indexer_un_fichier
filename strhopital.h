/***********************************************************************************
*
*                    STRUCTURES DES LISTES CHAINEES
*
************************************************************************************/
 typedef struct _str_medic
{
    char *Medicam;
    int quantite;
    struct _str_medic *p_medic_next;
    struct _str_medic *p_medic_prev;
} str_medic;

typedef struct _str_patient
{
    char       *NomPrenom;
    struct _str_patient *p_patient_next;
    struct _str_patient *p_patient_prev;
    str_medic     * p_medic_first;
    str_medic     * p_medic_last;
} str_patient;

typedef struct _str_hopital
{
    int caractere;
    struct _str_lg_mot *p_patient_first;
    struct _str_lg_mot *p_patient_last;

} str_hopital;
/***********************************************************************************
*
*                        GESTION DES INTERVALLES
*
************************************************************************************/
void init_hopital();
void maj_hopital(str_hopital *p_str_hopital, str_patient *p_str_patient);
str_hopital * chercher_intervalle( char * mot );
str_hopital * chercher_caractere(int car );

/***********************************************************************************
 *
 *                   Fn DE GESTION DES LISTES CHAINEES DE PATIENTS
 *
 ************************************************************************************/
void changer_maillon_tete_patient( str_patient * p_str_patient_first_new, str_patient * p_str_patient_first_old );
void inserer_maillon_patient( str_patient * p_str_patient, str_patient * p_str_patient_prev );
str_patient * creer_maillon_patient( str_patient * p_str_patient_prev, char *Nom_Prenom );
void supprimer_maillon_patient( str_patient * p_str_patient );
str_patient* chercher_maillon_patient(str_hopital * p_str_hopital, char *Nom_Prenom );
str_patient * trier_liste_patients( str_patient * p_str_patient );

/***********************************************************************************
 *
 *                      Fn DE GESTION DES LISTES CHAINEES DE MEDICAMENTS
 *
 ************************************************************************************/
void changer_maillon_tete_medic( str_medic * p_str_medic_first_new, str_medic * p_str_medic_first_old );
void inserer_maillon_medic( str_medic * p_str_medic, str_medic * p_str_medic_prev );
str_medic * creer_maillon_medic(str_medic * p_str_medic_first, str_medic * p_str_medic_prev, char * medicament, int quanti );
void supprimer_maillon_medic( str_medic * p_str_medic );
str_medic * chercher_maillon_medic (str_medic * p_str_medic_start, char * medicament , int quantit );
str_medic * trier_liste_medics( str_medic * p_str_medic );

/***********************************************************************************
 *
 *                        Fn DE GESTION DE L'HOPITAL
 *
 ************************************************************************************/
int creer_struct_hopital();
void afficher_hopital();
void afficher_liste_patients();
void trier_hopital();
void liberer_memoire_hopital();
void ajouter_patient(char *nomcomplet_patient);
void supprimer_patient(char *nomcomplet_patient);
int consommer_medicament(char *nomcomplet_patient,char *medicament, int quantite_a_consomer);
int position_2(char x,char* ch);
int position_1(char x,char* ch);
void extraire_mot_de_chaine(char* chaine,char* buff,int min,int max);
void reinit_var();
/***********************************************************************************
*
*                             Fns UTILISATEURS
*
************************************************************************************/
str_patient *chercher_patient_dans_hopital( char *nomcomplet_patient );
/***********************************************************************************
*
*                            GESTION MENU
*
************************************************************************************/
int menuprincipal(void);
void afficher_resultat_creer_struct_hopital();
void chercher_patient_dans_hopital_ask();
int creer_struct_hopital_ask();
void ajouter_patient_ask();
void supprimer_patient_ask();
void consommer_medicament_ask();
void erreur_init_hopital();
