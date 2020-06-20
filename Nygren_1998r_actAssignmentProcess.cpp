
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998r_actAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998r_actAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, k_rel_d );
    PROPERTYSLOT_SET_GET( Real, k_rel_i );

  }

  Nygren_1998r_actAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, k_rel_d );
  SIMPLE_SET_GET_METHOD( Real, k_rel_i );


  virtual void initialize()
  {
    Process::initialize();

    r_act  = getVariableReference( "r_act" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();
    Ca_d  = getVariableReference( "Ca_d" ).getVariable();

  }

  virtual void fire()
  {
    r_act->setValue( 1 * (203.800*(pow((Ca_i->getMolarConc()*1000)/((Ca_i->getMolarConc()*1000)+k_rel_i), 4.00000)+pow((Ca_d->getMolarConc()*1000)/((Ca_d->getMolarConc()*1000)+k_rel_d), 4.00000))) );

  }

 protected:

  Variable* r_act;
  Variable* Ca_i;
  Variable* Ca_d;

  Real k_rel_d;
  Real k_rel_i;

};

LIBECS_DM_INIT( Nygren_1998r_actAssignmentProcess, Process );
