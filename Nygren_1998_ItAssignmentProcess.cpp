
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_ItAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_ItAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_t );
  }

  Nygren_1998_ItAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_t );

  virtual void initialize()
  {
    Process::initialize();

    i_t  = getVariableReference( "i_t" ).getVariable();
    tau_r  = getVariableReference( "tau_r" ).getVariable();
    r_infinity  = getVariableReference( "r_infinity" ).getVariable();
    tau_s  = getVariableReference( "tau_s" ).getVariable();
    s_infinity  = getVariableReference( "s_infinity" ).getVariable();
    r  = getVariableReference( "r" ).getVariable();
    s  = getVariableReference( "s" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_K  = getVariableReference( "E_K" ).getVariable();

  }

  virtual void fire()
  {
    v = V->getValue();
    i_t->setValue( g_t*r->getValue()*s->getValue()*(v-E_K->getValue()) );
    tau_r->setValue( 0.00350000*exp(-(pow(v/30.0000, 2.00000)))+0.00150000 );
    r_infinity->setValue( 1.00000/(1.00000+exp((v-1.00000)/-11.0000)) );
    tau_s->setValue( 0.481200*exp(-(pow((v+52.4500)/14.9700, 2.00000)))+0.0141400 );
    s_infinity->setValue( 1.00000/(1.00000+exp((v+40.5000)/11.5000)) );
  }

 protected:

  Variable* i_t;
  Variable* tau_r;
  Variable* r_infinity;
  Variable* tau_s;
  Variable* s_infinity;
  Variable* r;
  Variable* s;
  Variable* V;
  Variable* E_K;

  Real g_t;
  Real v;
};

LIBECS_DM_INIT( Nygren_1998_ItAssignmentProcess, Process );
