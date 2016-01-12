/*
   Copyright (c) 2011, 2016, Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
*/

#include "ndb_mi.h"
#include "ha_ndbcluster_glue.h"

#include "rpl_mi.h"
#include "rpl_rli.h"

#ifdef HAVE_NDB_BINLOG

extern Master_info *active_mi;


uint32 ndb_mi_get_master_server_id()
{
  DBUG_ASSERT (active_mi != NULL);
  return (uint32) active_mi->master_id;
}

const char* ndb_mi_get_group_master_log_name()
{
  DBUG_ASSERT (active_mi != NULL);
  return active_mi->rli->get_group_master_log_name();
}

uint64 ndb_mi_get_group_master_log_pos()
{
  DBUG_ASSERT (active_mi != NULL);
  return (uint64) active_mi->rli->get_group_master_log_pos();
}

uint64 ndb_mi_get_future_event_relay_log_pos()
{
  DBUG_ASSERT (active_mi != NULL);
  return (uint64) active_mi->rli->get_future_event_relay_log_pos();
}

uint64 ndb_mi_get_group_relay_log_pos()
{
  DBUG_ASSERT (active_mi != NULL);
  return (uint64) active_mi->rli->get_group_relay_log_pos();
}

bool ndb_mi_get_ignore_server_id(uint32 server_id)
{
  DBUG_ASSERT (active_mi != NULL);
  return (active_mi->shall_ignore_server_id(server_id) != 0);
}

uint32 ndb_mi_get_slave_run_id()
{
  DBUG_ASSERT (active_mi != NULL);
  return active_mi->rli->slave_run_id;
}

ulong ndb_mi_get_relay_log_trans_retries()
{
  DBUG_ASSERT (active_mi != NULL);
  return active_mi->rli->trans_retries;
}

void ndb_mi_set_relay_log_trans_retries(ulong number)
{
  DBUG_ASSERT (active_mi != NULL);
  active_mi->rli->trans_retries = number;
}

bool ndb_mi_get_slave_sql_running()
{
  return active_mi->rli->slave_running;
}

#endif
