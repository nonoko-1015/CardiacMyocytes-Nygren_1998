
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_tAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_tAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_t );

  }

  Nygren_1998i_tAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_t );


  virtual void initialize()
  {
    Process::initialize();

    i_t  = getVariableReference( "i_t" ).getVariable();
    r  = getVariableReference( "r" ).getVariable();
    s  = getVariableReference( "s" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_K  = getVariableReference( "E_K" ).getVariable();

  }

  virtual void fire()
  {
    i_t->setValue( 1 * (g_t*r->getValue()*s->getValue()*(V->getValue()-E_K->getValue())) );

  }

 protected:

  Variable* i_t;
  Variable* r;
  Variable* s;
  Variable* V;
  Variable* E_K;

  Real g_t;

};

LIBECS_DM_INIT( Nygren_1998i_tAssignmentProcess, Process );
