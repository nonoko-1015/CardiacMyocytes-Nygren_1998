
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_K_iFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_K_iFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998j_K_iFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    K_c  = getVariableReference( "K_c" ).getVariable();
    K_i  = getVariableReference( "K_i" ).getVariable();
    i_t  = getVariableReference( "i_t" ).getVariable();
    i_sus  = getVariableReference( "i_sus" ).getVariable();
    i_K1  = getVariableReference( "i_K1" ).getVariable();
    i_Kr  = getVariableReference( "i_Kr" ).getVariable();
    i_Ks  = getVariableReference( "i_Ks" ).getVariable();
    i_NaK  = getVariableReference( "i_NaK" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( ((i_t->getValue()+i_sus->getValue()+i_K1->getValue()+i_Kr->getValue()+i_Ks->getValue())-2.00000*i_NaK->getValue())/F * N_A *1.0e-12 );
  }

 protected:

  Variable* K_c;
  Variable* K_i;
  Variable* i_t;
  Variable* i_sus;
  Variable* i_K1;
  Variable* i_Kr;
  Variable* i_Ks;
  Variable* i_NaK;

  Real F;

};

LIBECS_DM_INIT( Nygren_1998j_K_iFluxProcess, Process );
