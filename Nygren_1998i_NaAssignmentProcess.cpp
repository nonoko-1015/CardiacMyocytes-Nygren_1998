
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_NaAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_NaAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, R );
    PROPERTYSLOT_SET_GET( Real, P_Na );
    PROPERTYSLOT_SET_GET( Real, T );
    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998i_NaAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, R );
  SIMPLE_SET_GET_METHOD( Real, P_Na );
  SIMPLE_SET_GET_METHOD( Real, T );
  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    i_Na  = getVariableReference( "i_Na" ).getVariable();
    m  = getVariableReference( "m" ).getVariable();
    h1  = getVariableReference( "h1" ).getVariable();
    h2  = getVariableReference( "h2" ).getVariable();
    Na_c  = getVariableReference( "Na_c" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_Na  = getVariableReference( "E_Na" ).getVariable();

  }

  virtual void fire()
  {
    i_Na->setValue( 1 * ((((P_Na*(pow(m->getValue(), 3.00000))*(0.900000*h1->getValue()+0.100000*h2->getValue())*(Na_c->getMolarConc()*1000)*V->getValue()*(pow(F, 2.00000)))/(R*T))*(exp(((V->getValue()-E_Na->getValue())*F)/(R*T))-1.00000))/(exp((V->getValue()*F)/(R*T))-1.00000)) );

  }

 protected:

  Variable* i_Na;
  Variable* m;
  Variable* h1;
  Variable* h2;
  Variable* Na_c;
  Variable* V;
  Variable* E_Na;

  Real R;
  Real P_Na;
  Real T;
  Real F;

};

LIBECS_DM_INIT( Nygren_1998i_NaAssignmentProcess, Process );
