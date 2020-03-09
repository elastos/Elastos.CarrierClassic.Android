package org.elastos.carrier;

import org.elastos.carrier.exceptions.CarrierException;

public abstract class CarrierExtension {
    private Carrier carrier;

    static class TurnServerInfo {
        private String server;
        private String username;
        private String password;
        private String realm;
        private int port;

        TurnServerInfo() {
            // TODO:
        }

        public String getServer() {
            return server;
        }

        public int getPort() {
            return port;
        }

        public String getUsername() {
            return username;
        }

        public String getPassword() {
            return password;
        }

        public String getRealm() {
            return realm;
        }

    }

    abstract protected void onFriendInvite(Carrier carrier, String from, String data);

    protected CarrierExtension(Carrier carrier) {
        this.carrier = carrier;
    }

    protected TurnServerInfo getTurnServerInfo() {
        // TODO:
        return new TurnServerInfo();
    }

    protected void inviteFriend(String to, String data, FriendInviteResponseHandler handler)
            throws CarrierException {
        // TODO
    }

    protected void replyFriendInvite(String to, int status, String reason, String data)
            throws CarrierException {
        // TODO:
    }

    protected void registerExtension() {
        // TODO:
    }
}
