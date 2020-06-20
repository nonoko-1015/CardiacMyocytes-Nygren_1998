
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_Ca_LAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_Ca_LAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, E_Ca_app );
    PROPERTYSLOT_SET_GET( Real, g_Ca_L );

  }

  Nygren_1998i_Ca_LAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, E_Ca_app );
  SIMPLE_SET_GET_METHOD( Real, g_Ca_L );


  virtual void initialize()
  {
    Process::initialize();

    i_Ca_L  = getVariableReference( "i_Ca_L" ).getVariable();
    d_L  = getVariableReference( "d_L" ).getVariable();
    f_Ca  = getVariableReference( "f_Ca" ).getVariable();
    f_L_1  = getVariableReference( "f_L_1" ).getVariable();
    f_L_2  = getVariableReference( "f_L_2" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();

  }

  virtual void fire()
  {
    i_Ca_L->setValue( 1 * (g_Ca_L*d_L->getValue()*(f_Ca->getValue()*f_L_1->getValue()+(1.00000-f_Ca->getValue())*f_L_2->getValue())*(V->getValue()-E_Ca_app)) );

  }

 protected:

  Variable* i_Ca_L;
  Variable* d_L;
  Variable* f_Ca;
  Variable* f_L_1;
  Variable* f_L_2;
  Variable* V;

  Real E_Ca_app;
  Real g_Ca_L;

};

LIBECS_DM_INIT( Nygren_1998i_Ca_LAssignmentProcess, Process );
