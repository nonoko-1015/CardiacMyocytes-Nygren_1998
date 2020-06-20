
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_VFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_VFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, Cm );

  }

  Nygren_1998v_VFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, Cm );


  virtual void initialize()
  {
    Process::initialize();

    V  = getVariableReference( "V" ).getVariable();
    i_Stim  = getVariableReference( "i_Stim" ).getVariable();
    i_Na  = getVariableReference( "i_Na" ).getVariable();
    i_Ca_L  = getVariableReference( "i_Ca_L" ).getVariable();
    i_t  = getVariableReference( "i_t" ).getVariable();
    i_sus  = getVariableReference( "i_sus" ).getVariable();
    i_K1  = getVariableReference( "i_K1" ).getVariable();
    i_Kr  = getVariableReference( "i_Kr" ).getVariable();
    i_Ks  = getVariableReference( "i_Ks" ).getVariable();
    i_B_Na  = getVariableReference( "i_B_Na" ).getVariable();
    i_B_Ca  = getVariableReference( "i_B_Ca" ).getVariable();
    i_NaK  = getVariableReference( "i_NaK" ).getVariable();
    i_CaP  = getVariableReference( "i_CaP" ).getVariable();
    i_NaCa  = getVariableReference( "i_NaCa" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (-1.00000/Cm)*(i_Stim->getValue()+i_Na->getValue()+i_Ca_L->getValue()+i_t->getValue()+i_sus->getValue()+i_K1->getValue()+i_Kr->getValue()+i_Ks->getValue()+i_B_Na->getValue()+i_B_Ca->getValue()+i_NaK->getValue()+i_CaP->getValue()+i_NaCa->getValue()) );
  }

 protected:

  Variable* V;
  Variable* i_Stim;
  Variable* i_Na;
  Variable* i_Ca_L;
  Variable* i_t;
  Variable* i_sus;
  Variable* i_K1;
  Variable* i_Kr;
  Variable* i_Ks;
  Variable* i_B_Na;
  Variable* i_B_Ca;
  Variable* i_NaK;
  Variable* i_CaP;
  Variable* i_NaCa;

  Real Cm;

};

LIBECS_DM_INIT( Nygren_1998v_VFluxProcess, Process );
