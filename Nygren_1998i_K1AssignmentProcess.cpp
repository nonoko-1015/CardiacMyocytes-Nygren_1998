
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_K1AssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_K1AssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_K1 );
    PROPERTYSLOT_SET_GET( Real, R );
    PROPERTYSLOT_SET_GET( Real, T );
    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998i_K1AssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_K1 );
  SIMPLE_SET_GET_METHOD( Real, R );
  SIMPLE_SET_GET_METHOD( Real, T );
  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    i_K1  = getVariableReference( "i_K1" ).getVariable();
    K_c  = getVariableReference( "K_c" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_K  = getVariableReference( "E_K" ).getVariable();

  }

  virtual void fire()
  {
    i_K1->setValue( 1 * ((g_K1*(pow((K_c->getMolarConc()*1000)/1.00000, 0.445700))*(V->getValue()-E_K->getValue()))/(1.00000+exp((1.50000*((V->getValue()-E_K->getValue())+3.60000)*F)/(R*T)))) );

  }

 protected:

  Variable* i_K1;
  Variable* K_c;
  Variable* V;
  Variable* E_K;

  Real g_K1;
  Real R;
  Real T;
  Real F;

};

LIBECS_DM_INIT( Nygren_1998i_K1AssignmentProcess, Process );
